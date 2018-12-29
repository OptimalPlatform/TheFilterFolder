/*
 * aVecWin.c
 *
 *  Created on: 29 dec. 2018
 *      Author: Olof
 */


//Menu for the kalmanfilter
#include "main.h"
#include "DIALOG.h"
#include "GUI.h"
#include <stdlib.h>

//Constant
uint8_t doneFlag;

uint8_t var;

float32_t b_1;
float32_t b_2;
float32_t b_3;
float32_t b_4;

/*********************************************************************
 *
 *       Static data
 *
 **********************************************************************
 */

/* Dialog resource of numpad */
static const GUI_WIDGET_CREATE_INFO _aDialogbVecWin[] =
		{
				/*  Function                 Text      Id                 Px   Py   Dx   Dy */
				{ WINDOW_CreateIndirect, 0, 0, 0, 0, 240, 320 },
				{ BUTTON_CreateIndirect, "Set b_1", GUI_ID_USER	+ 1, 5, 45, 225, 35 },
				{ BUTTON_CreateIndirect, "Set b_2", GUI_ID_USER + 2, 5, 85, 225, 35 },
				{ BUTTON_CreateIndirect, "Set b_3",GUI_ID_USER + 3, 5, 125, 225, 35 },
				{ BUTTON_CreateIndirect, "Set b_4",GUI_ID_USER + 4, 5, 165, 225, 35 },
				{ BUTTON_CreateIndirect,"Done",GUI_ID_USER + 0, 5, 205, 225, 35 },
		};

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

 */

static void _cbDialogbVecWin(WM_MESSAGE * pMsg) {
	int i, NCode, Id, Pressed = 0;
	WM_HWIN hDlg, hItem;
	hDlg = pMsg->hWin;
	switch (pMsg->MsgId) {
	case WM_PAINT:
		GUI_SetBkColor(0x000000);
		GUI_Clear();
	break;

	case WM_INIT_DIALOG:
		for (i = 0; i <= GUI_COUNTOF(_aDialogbVecWin); i++) {
			hItem = WM_GetDialogItem(hDlg, GUI_ID_USER + i);
			BUTTON_SetFocussable(hItem, 1); // Set all buttons focussable
		}
		break;

	case WM_NOTIFY_PARENT:
		Id = WM_GetId(pMsg->hWinSrc); // Id of widget
		NCode = pMsg->Data.v; // Notification code
		int Key = 0;

		switch (NCode) {
			case WM_NOTIFICATION_RELEASED:
				if (Id == GUI_ID_USER + 0) {
					doneFlag = 2;
					GUI_EndDialog(hDlg, 1);
				} else if (Id == GUI_ID_USER + 1) {
					var = 1;
					doneFlag = 1;
					GUI_EndDialog(hDlg, 1);
				} else if (Id == GUI_ID_USER + 2) {
					var = 2;
					doneFlag = 1;
					GUI_EndDialog(hDlg, 1);
				} else if (Id == GUI_ID_USER + 3) {
					var = 3;
					doneFlag = 1;
					GUI_EndDialog(hDlg, 1);
				} else if (Id == GUI_ID_USER + 4) {
					var = 3;
					doneFlag = 1;
					GUI_EndDialog(hDlg, 1);
				}
			GUI_SendKeyMsg(Key, Pressed); // Send a key message to the focussed window
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
/**********************b***********************************************
 *
 *       _cbDesktop
 *
 * Purpose:
 *   This routine handles the drawing of the desktop window.
 */

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
void bVecMenu(struct FilterState* fState) {
	WM_HWIN hMenu;

	var = 0;

	b_1 = fState->b_1;
	b_2 = fState->b_2;
	b_3 = fState->b_3;
	b_4 = fState->b_4;

	while (doneFlag != 2)
	{
		switch (var)
		{
		case '0':
			GUI_SelectLayer(0);
			hMenu = GUI_CreateDialogBox(_aDialogbVecWin, GUI_COUNTOF(_aDialogbVecWin), _cbDialogbVecWin, WM_HBKWIN, 0, 0);

			WM_SetCallback(hMenu, _cbDialogbVecWin);
			WIDGET_SetFocusable(hMenu, 1);
			break;

		case '1':
			b_1 =  keypad();
			var = 0;;
			doneFlag = 0;
			break;

		case '2':
			b_2 = keypad();
			var = 0;
			doneFlag = 0;
			break;

		case '3':
			b_3 = keypad();
			var = 0;
			doneFlag = 0;
			break;

		case '4':
			b_4 = keypad();
			var = 0;
			doneFlag = 0;
			break;

		case 'G':
			doneFlag = 2;
			break;

		}
		GUI_Delay(200);
	}

		fState->b_1 = b_1;
		fState->b_2 = b_2;
		fState->b_3 = b_3;
		fState->b_4 = b_4;
}

/*************************** End of file ****************************/

