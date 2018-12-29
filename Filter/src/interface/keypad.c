/*********************************************************************
 *                SEGGER Microcontroller GmbH & Co. KG                *
 *        Solutions for real time microcontroller applications        *
 **********************************************************************
 *                                                                    *
 *        (c) 1996 - 2012  SEGGER Microcontroller GmbH & Co. KG       *
 *                                                                    *
 *        Internet: www.segger.com    Support:  support@segger.com    *
 *                                                                    *
 **********************************************************************
 ** emWin V5.14 - Graphical user interface for embedded applications **
 All  Intellectual Property rights  in the Software belongs to  SEGGER.
 emWin is protected by  international copyright laws.  Knowledge of the
 source code may not be used to write a similar product.  This file may
 only be used in accordance with the following terms:
 The software has been licensed to Energy Micro AS whose registered office
 is situated at  Sandakerveien 118, N-0484 Oslo, NORWAY solely
 for  the  purposes  of  creating  libraries  for Energy Micros ARM Cortex-M3, M4F
 processor-based  devices,  sublicensed  and distributed  under the terms and
 conditions  of  the   End  User  License Agreement supplied by Energy Micro AS.
 Full source code is available at: www.segger.com
 We appreciate your understanding and fairness.
 ----------------------------------------------------------------------
 File        : WIDGET_NumPad.c
 Purpose     : Shows how to use a numpad as input device on a touch screen
 ---------------------------END-OF-HEADER------------------------------
 */
#include "main.h"
#include "DIALOG.h"
#include "GUI.h"
#include <stdlib.h>

//functions
float32_t concanate(float32_t x, int y);
//float decimal(float x, int y);

//Constant
float32_t num = 0; //value on display
int8_t numSign = 1; //1 for + -1 for -
uint8_t doneFlag = 0;
//int decFlag = 1; // 1 for normal 0 for dec mode
/*********************************************************************
 *
 *       Static data
 *
 **********************************************************************
 */

/* Dialog resource of numpad */
static const GUI_WIDGET_CREATE_INFO _aDialogNumPad[] = {
/*  Function                 Text      Id                 Px   Py   Dx   Dy */
{ WINDOW_CreateIndirect, 0, 0, 0, 0, 240, 320 }, { EDIT_CreateIndirect, 0,
GUI_ID_EDIT0, 10, 10, 200, 40, 0, 0 }, { BUTTON_CreateIndirect, "7",
GUI_ID_USER + 7, 5, 65, 50, 40 }, { BUTTON_CreateIndirect, "8",
GUI_ID_USER + 8, 65, 65, 50, 40 }, { BUTTON_CreateIndirect, "9",
GUI_ID_USER + 9, 125, 65, 50, 40 }, { BUTTON_CreateIndirect, "4",
GUI_ID_USER + 4, 5, 125, 50, 40 }, { BUTTON_CreateIndirect, "5",
GUI_ID_USER + 5, 65, 125, 50, 40 }, { BUTTON_CreateIndirect, "6",
GUI_ID_USER + 6, 125, 125, 50, 40 }, { BUTTON_CreateIndirect, "1",
GUI_ID_USER + 1, 5, 185, 50, 40 }, { BUTTON_CreateIndirect, "2",
GUI_ID_USER + 2, 65, 185, 50, 40 }, { BUTTON_CreateIndirect, "3",
GUI_ID_USER + 3, 125, 185, 50, 40 }, { BUTTON_CreateIndirect, "Cancel",
GUI_ID_CANCEL, 5, 245, 50, 40 }, { BUTTON_CreateIndirect, "0",
GUI_ID_USER + 0, 65, 245, 50, 40 }, { BUTTON_CreateIndirect, "OK",
GUI_ID_OK, 125, 245, 50, 40 }, { BUTTON_CreateIndirect, "-", GUI_ID_USER + 10,
		185, 65, 40, 100 }, { BUTTON_CreateIndirect, ".", GUI_ID_USER + 11, 185,
		185, 40, 100 } };

/*********************************************************************
 *
 *       Static code
 *
 **********************************************************************
 */
/*********************************************************************
 *
 *       _cbDialogNumPad
 *
 * Purpose:
 *   Callback function of the numpad.
 */

static void _cbDialogNumPad(WM_MESSAGE * pMsg) {
	int i, NCode, Id, Pressed = 0;
	WM_HWIN hDlg, hItem;
	hDlg = pMsg->hWin;
	switch (pMsg->MsgId) {

	case WM_PAINT:
		GUI_SetBkColor(0x000000);
		GUI_Clear();
		break;

	case WM_INIT_DIALOG:
		for (i = 0; i <= 11; i++) {
			hItem = WM_GetDialogItem(hDlg, GUI_ID_USER + i);
			BUTTON_SetFocussable(hItem, 1); // Set all buttons non focussable
		}
		hItem = WM_GetDialogItem(hDlg, GUI_ID_OK);
		BUTTON_SetFocussable(hItem, 1);
		hItem = WM_GetDialogItem(hDlg, GUI_ID_CANCEL);
		BUTTON_SetFocussable(hItem, 1);
		hItem = WM_GetDialogItem(hDlg, GUI_ID_EDIT0);
		EDIT_SetFocussable(hItem, 0);
		EDIT_SetFloatMode(hItem, 0, -100000, 100000, 3,
				GUI_EDIT_SUPPRESS_LEADING_ZEROES);
		EDIT_SetFont(hItem, GUI_FONT_24_1);
		break;

	case WM_NOTIFY_PARENT:
		Id = WM_GetId(pMsg->hWinSrc); // Id of widget
		NCode = pMsg->Data.v; // Notification code
		int Key = 0;
		switch (NCode) {
		case WM_NOTIFICATION_RELEASED:
			if ((Id >= GUI_ID_USER) && (Id <= (GUI_ID_USER + 9))) {
				char acBuffer[10];
				BUTTON_GetText(pMsg->hWinSrc, acBuffer, sizeof(acBuffer)); // Get the text of the button
				Key = acBuffer[0];
				//if (decFlag == 1) {
				num = concanate(num, (int) Key - 48);
				//} else if (decFlag == 0) {
					//num = decimal(num, (int) Key - 48);
				//}
			} else if (Id == GUI_ID_OK) {
				doneFlag = 1;
				GUI_EndDialog(hDlg, 1);
			} else if (Id == GUI_ID_CANCEL) {
				doneFlag = 2;
				GUI_EndDialog(hDlg, 2);
			} else if (Id == GUI_ID_USER + 10) {
				Key = 0;
				numSign = -1;
			} else if (Id == GUI_ID_USER + 11) {
				Key = 0;
				//decFlag = 0; 	//not needed as of this point
			}
			GUI_SendKeyMsg(Key, Pressed); // Send a key message to the focussed window

			 if (numSign == -1) {
			 num = -abs(num);
			 }

			hItem = WM_GetDialogItem(hDlg, GUI_ID_EDIT0);
			EDIT_SetValue(hItem, num);
			break;
		case WM_NOTIFICATION_CLICKED:
			Pressed = 1;
			break;
		}

		break;
	default:
		WM_DefaultProc(pMsg);
	}
}


/*********************************************************************
 *
 *       Exported code
 *
 **********************************************************************
 */
/*********************************************************************
 *
 *       MainTask
 */
int keypad(void) {
	WM_HWIN hNumPad;
	int doneFlag = 0;

	GUI_SelectLayer(0);

	hNumPad = GUI_CreateDialogBox(_aDialogNumPad, GUI_COUNTOF(_aDialogNumPad),_cbDialogNumPad, WM_HBKWIN, 0, 0);

	WM_SetCallback(hNumPad, _cbDialogNumPad);
	WIDGET_SetFocusable(hNumPad, 1);

	while (doneFlag == 0)
	{
		GUI_ExecCreatedDialog(hNumPad);
		GUI_Delay(200);
	}
		if (doneFlag == 2)
	{
		//resets num if cancel is pressed
		num = 0;
	}
	//return the set number, have to be devided by 1000 since we have 0.001 resolution
	return num/1000;
}

//concanates 1 and 2 as 12 etc
float32_t concanate(float32_t x, int y) {
	x = abs(x);
	int pow = 10;
	while (y >= pow) {
		pow *= 10;
	}
	return x * pow + y;
}

//to allow for free use of decimal comma, not used as of this point
/*
float decimal(float x, int y) {
	x = abs(x);
	float num = x;
	int count = 1;
	num = num - (int) num;
	while (num >= 0.0001) {
		num = num * 10;
		num = num - (int) num;
		count = count + 1;
	}
	float pow = 1;
	for (int i = 1; i <= count; i++) {
		pow *= 0.1;
	}
	return x + pow * y;
}
*/

/*************************** End of file ****************************/

