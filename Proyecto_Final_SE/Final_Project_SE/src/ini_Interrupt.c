/*
 * ini_Interrupt.c
 *
 *  Created on: 23 dic 2023
 *      Author: Hezitzaile
 */

#include "hal_data.h"
#include "ini_interrupt.h"

/*******************************************************************************************************************//**
 * @brief       This functions initializes ICU module.
 * @param[IN]   None
 * @retval      FSP_SUCCESS                  Upon successful open of ICU module
 * @retval      Any Other Error code apart from FSP_SUCCESS  Unsuccessful open
 **********************************************************************************************************************/
fsp_err_t icu_init(void)
{
    fsp_err_t err = FSP_SUCCESS;

    // Open ICU module
    err = R_ICU_ExternalIrqOpen(&push_button_ctrl, &push_button_cfg);
    // Handle error
    if (FSP_SUCCESS != err)
    {
        // ICU Open failure message
        //APP_ERR_PRINT ("\r\n**R_ICU_ExternalIrqOpen API FAILED**\r\n");
    }
    return err;
}


/*******************************************************************************************************************//**
 * @brief       This function enables external interrupt for specified channel.
 * @param[IN]   None
 * @retval      FSP_SUCCESS                  Upon successful enable of ICU module
 * @retval      Any Other Error code apart from FSP_SUCCESS  Unsuccessful open
 **********************************************************************************************************************/
fsp_err_t icu_enable(void)
{
    fsp_err_t err = FSP_SUCCESS;

    // Enable ICU module
    err = R_ICU_ExternalIrqEnable(&push_button_ctrl);
    // Handle error
    if (FSP_SUCCESS != err)
    {
        // ICU Enable failure message
        //APP_ERR_PRINT ("\r\n**R_ICU_ExternalIrqEnable API FAILED**\r\n");
    }
    return err;
}


/*******************************************************************************************************************//**
 * @brief       This function closes opened ICU module before the project ends up in an Error Trap.
 * @param[IN]   None
 * @retval      None
 **********************************************************************************************************************/
void icu_deinit(void)
{
    fsp_err_t err = FSP_SUCCESS;

    // Close ICU module
    err = R_ICU_ExternalIrqClose(&push_button_ctrl);
    // Handle error
    if (FSP_SUCCESS != err)
    {
        // ICU Close failure message
        //APP_ERR_PRINT("\r\n**R_ICU_ExternalIrqClose API FAILED**\r\n");
    }
}
