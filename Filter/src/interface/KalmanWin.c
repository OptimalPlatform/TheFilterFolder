//Menu for the kalmanfilter
#include "main.h"
#include "DIALOG.h"
#include "GUI.h"
#include <stdlib.h>

//Constant
uint8_t doneFlag;
char filterState;

/*********************************************************************
 *
 *       Static data
 *
 **********************************************************************
 */

/* Dialog resource of numpad */
static const GUI_WIDGET_CREATE_INFO _aDialogKalmanWin[] =
		{
				/*  Function                 Text      Id                 Px   Py   Dx   Dy */
				{ WINDOW_CreateIndirect, 0, 0, 0, 0, 240, 320 },
				{ BUTTON_CreateIndirect, "Set modelorder", GUI_ID_USER + 5, 5, 5,225, 35 },
				{ BUTTON_CreateIndirect, "Set init MSE", GUI_ID_USER	+ 0, 5, 45, 225, 35 },
				{ BUTTON_CreateIndirect, "Set init x", GUI_ID_USER + 1, 5, 85, 225, 35 },
				{ BUTTON_CreateIndirect, "Set C_u",GUI_ID_USER + 2, 5, 125, 225, 35 },
				{ BUTTON_CreateIndirect, "Set C_w",GUI_ID_USER + 3, 5, 165, 225, 35 },
				{ BUTTON_CreateIndirect, "Set a vector", GUI_ID_USER + 6, 5, 205 ,225 ,35 },
				{ BUTTON_CreateIndirect, "Set b vector", GUI_ID_USER + 7, 5, 245, 225, 35 },
				{ BUTTON_CreateIndirect,"Start filtering",GUI_ID_USER + 4, 5, 285, 225, 35 }
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

static void _cbDialogKalmanWin(WM_MESSAGE * pMsg) {
	int i, NCode, Id, Pressed = 0;
	WM_HWIN hDlg, hItem;
	hDlg = pMsg->hWin;
	switch (pMsg->MsgId) {
	case WM_PAINT:
		GUI_SetBkColor(0x000000);
		GUI_Clear();
	break;

	case WM_INIT_DIALOG:
		for (i = 0; i <= GUI_COUNTOF(_aDialogKalmanWin); i++) {
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
					//MSE
					filterState = 'M';
					doneFlag = 1;
					GUI_EndDialog(hDlg, 1);
				} else if (Id == GUI_ID_USER + 1) {
					//x
					filterState = 'X';
					doneFlag = 1;
					GUI_EndDialog(hDlg, 1);
				} else if (Id == GUI_ID_USER + 2) {
					//C_u
					filterState = 'R';
					doneFlag = 1;
					GUI_EndDialog(hDlg, 1);
				} else if (Id == GUI_ID_USER + 3) {
					//c_w
					filterState = 'Q';
					doneFlag = 1;
					GUI_EndDialog(hDlg, 1);
				} else if (Id == GUI_ID_USER + 4) {
					//done
					filterState = 'G';
					doneFlag = 1;
					GUI_EndDialog(hDlg, 1);
				} else if (Id == GUI_ID_USER + 5) {
					//order
					filterState = 'O';
					doneFlag = 1;
					GUI_EndDialog(hDlg,0);
				} else if (Id == GUI_ID_USER + 6) {
					//a vec
					filterState = 'a';
					doneFlag = 1;
					GUI_EndDialog(hDlg,1);
				} else if (Id == GUI_ID_USER + 7) {
					// b vec
					filterState = 'b';
					doneFlag = 1;
					GUI_EndDialog(hDlg,1);
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
void KalmanMenu(struct FilterState* fState) {
	WM_HWIN hMenu;
	doneFlag = fState->doneFlag;
	 filterState = fState->filterState;

	 GUI_SelectLayer(0);

	hMenu = GUI_CreateDialogBox(_aDialogKalmanWin, GUI_COUNTOF(_aDialogKalmanWin), _cbDialogKalmanWin, WM_HBKWIN, 0, 0);

	WM_SetCallback(hMenu, _cbDialogKalmanWin);
	WIDGET_SetFocusable(hMenu, 1);

	while (doneFlag == 0)
	{
		GUI_Delay(200);
	}

	fState->filterState = filterState;
}
