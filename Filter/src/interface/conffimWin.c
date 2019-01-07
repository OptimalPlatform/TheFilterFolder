/*
 * conffimWin.c
 *
 *  Created on: 7 jan. 2019
 *      Author: Olof
 */

#include "main.h"
#include "DIALOG.h"
#include "GUI.h"
#include <stdlib.h>

uint8_t doneFlag;
float32_t filterOrder;
float32_t initMSE;
float32_t initValue;

float32_t C_u;
float32_t C_w;

float32_t a_1;
float32_t a_2;
float32_t a_3;
float32_t a_4;

float32_t b_1;
float32_t b_2;
float32_t b_3;
float32_t b_4;

static const GUI_WIDGET_CREATE_INFO _aDialogConfirmWin[] = {
/*  Function                 Text      Id                 Px   Py   Dx   Dy */
{ WINDOW_CreateIndirect, 0, 0, 0, 0, 240, 320 }, { BUTTON_CreateIndirect,
		"Confirm filter", GUI_ID_USER + 0, 5, 280, 225, 35 },
		{ BUTTON_CreateIndirect, "Change param", GUI_ID_USER + 1, 5, 240, 225,
				35 }, };

static void _cbDialogConfirmWin(WM_MESSAGE * pMsg) {
	int i, NCode, Id, Pressed = 0;
	WM_HWIN hDlg, hItem;
	hDlg = pMsg->hWin;
	switch (pMsg->MsgId) {
	case WM_PAINT:
		GUI_SetBkColor(0x000000);
		GUI_Clear();
		GUI_SetFont(&GUI_Font16_ASCII);

		GUI_DispStringAt("Filter Order:", 5, 5);
		GUI_DispDecAt(filterOrder, 5, 25, 1);

		GUI_DispStringAt("Init x:	                  	initMSE:", 5, 45);
		GUI_GotoXY(5,65);
		GUI_DispFloat(initValue,4);
		GUI_GotoXY(125,65);
		GUI_DispFloat(initMSE,  4);

		GUI_DispStringAt("C_w:                      C_u:", 5, 85);
		GUI_GotoXY(5,105);
		GUI_DispFloat(C_w,  4);
		GUI_GotoXY(125,105);
		GUI_DispFloat(C_u,  4);

		GUI_DispStringAt("A vec:", 5, 125);
		GUI_GotoXY(5,145);
		GUI_DispFloat(a_1,  4);
		GUI_GotoXY(65,145);
		GUI_DispFloat(a_2,  4);
		GUI_GotoXY(125,145);
		GUI_DispFloat(a_3,  4);
		GUI_GotoXY(185,145);
		GUI_DispFloat(a_4,  4);

		GUI_DispStringAt("B vec:", 5, 165);
		GUI_GotoXY(5,185);
		GUI_DispFloat(b_1,  4);
		GUI_GotoXY(65,185);
		GUI_DispFloat(b_2,  4);
		GUI_GotoXY(125,185);
		GUI_DispFloat(b_3,  4);
		GUI_GotoXY(185,185);
		GUI_DispFloat(b_4,  4);
		break;

	case WM_INIT_DIALOG:
		for (i = 0; i <= GUI_COUNTOF(_aDialogConfirmWin); i++) {
			hItem = WM_GetDialogItem(hDlg, GUI_ID_USER + i);
			BUTTON_SetFocussable(hItem, 1); // Set all buttons focussable
		}
		//GUI_Clear();
		break;

	case WM_NOTIFY_PARENT:
		Id = WM_GetId(pMsg->hWinSrc); // Id of widget
		NCode = pMsg->Data.v; // Notification code
		int Key = 0;

		switch (NCode) {
		case WM_NOTIFICATION_RELEASED:
			if (Id == GUI_ID_USER + 0) {
				doneFlag = 1;
				GUI_EndDialog(hDlg, 0);
			} else if (Id == GUI_ID_USER + 1) {
				doneFlag = 2;
				GUI_EndDialog(hDlg, 0);
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

void confirmWin(struct FilterState* fState) {
	WM_HWIN hMenu;
	doneFlag = fState->doneFlag;
	;
	filterOrder = fState->filterOrder;
	initMSE = fState->initMSE;
	initValue = fState->initValue;

	C_u = fState->R_1;
	C_w = fState->R_2;

	a_1 = fState->a_1;
	a_2 = fState->a_2;
	a_3 = fState->a_3;
	a_4 = fState->a_4;

	b_1 = fState->b_1;
	b_2 = fState->b_2;
	b_3 = fState->b_3;
	b_4 = fState->b_4;

	GUI_SelectLayer(0);

	hMenu = GUI_CreateDialogBox(_aDialogConfirmWin,
			GUI_COUNTOF(_aDialogConfirmWin), _cbDialogConfirmWin, WM_HBKWIN, 0,
			0);

	WM_SetCallback(hMenu, _cbDialogConfirmWin);
	WIDGET_SetFocusable(hMenu, 1);

	while (doneFlag == 0) {
		GUI_Delay(200);
	}
	if (doneFlag == 1) {
		fState->doneFlag = doneFlag;
	}
	fState->filterType = 'K';
}
