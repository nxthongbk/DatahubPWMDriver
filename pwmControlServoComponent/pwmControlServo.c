#include "legato.h"
#include "interfaces.h"


#define PWM_CHANNEL_NAME "pwm/channel1/value"

#define PWM_CHANNEL_DATA "/app/pwmConfigureToDatahub/pwm/channel1/value"

#define PWM_CHANNEL_OBS "pwmchannelOffLimits"

#define PWM_CHANNEL_LOWER_LIMIT 10.0000
#define PWM_CHANNEL_UPPER_LIMIT 150.0000

//--------------------------------------------------------------------------------------------------
/**
 * Call-back function called when an update is received from the Data Hub for the latitude value.
 */
//--------------------------------------------------------------------------------------------------
static void PWMChannelUpdateHandler
(
	double timestamp,
	double value,
	void* contextPtr
)
{
	LE_DEBUG("PWM Servo Angle: = %lf (timestamped %lf)", value, timestamp);
}


//--------------------------------------------------------------------------------------------------
/**
 * Call-back function called when an update is received from the Data Hub for the led matrix value.
 */
//--------------------------------------------------------------------------------------------------
static void PWMChannelObservationUpdateHandler
(
	double timestamp,	///< time stamp
	double value,		///< air sensor value,
	void* contextPtr	///< not used 
)
{
	
	ma_pwm_set_angle(1, value);

	LE_INFO("Observed filtered pwm angle = %lf (timestamped %lf)", value, timestamp);	
}


COMPONENT_INIT
{
	
	LE_INFO("Servo start \n");
	ma_pwm_servo_init();

	

	le_result_t result;

	// This will be received from the Data Hub.
	result = io_CreateOutput(PWM_CHANNEL_NAME, IO_DATA_TYPE_NUMERIC, "degrees");
	LE_ASSERT(result == LE_OK);

	// Register for notification of updates to the counter value.
	io_AddNumericPushHandler(PWM_CHANNEL_NAME, PWMChannelUpdateHandler, NULL);

	// Connect to the sensor
	result = admin_SetSource("/app/pwmControlServo/" PWM_CHANNEL_NAME, PWM_CHANNEL_DATA);
	LE_ASSERT(result == LE_OK);

	// Create observation (filter) for air sensor. To set up the "dead band" filter,
	// lower limit assigned to high limit and vice versa (see admin.io doc for details).
	admin_CreateObs(PWM_CHANNEL_OBS);
	admin_SetLowLimit(PWM_CHANNEL_OBS, PWM_CHANNEL_LOWER_LIMIT);
	admin_SetHighLimit(PWM_CHANNEL_OBS, PWM_CHANNEL_UPPER_LIMIT);
	result = admin_SetSource("/obs/" PWM_CHANNEL_OBS, PWM_CHANNEL_DATA);
	LE_ASSERT(result == LE_OK);
	admin_AddNumericPushHandler("/obs/" PWM_CHANNEL_OBS, PWMChannelObservationUpdateHandler, NULL);

	LE_ASSERT(result == LE_OK);
}
