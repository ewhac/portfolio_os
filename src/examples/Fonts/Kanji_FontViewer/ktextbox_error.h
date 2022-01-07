#ifndef _KTEXTBOXERROR_H
#define _KTEXTBOXERROR_H

/******************************************************************************
**
**  $Id: ktextbox_error.h,v 1.3 1994/11/21 22:06:49 vertex Exp $
**
******************************************************************************/


#ifndef __OPERROR_H
#include "operror.h"
#endif

#define ER_KTextBox_NoError 		 0	/* ����I�� */
										/* No error encountered. */
#define ER_KTextBox_BadParameter	-1	/* �p�����[�^���s���ł� */
										/* Illegal parameter error. */
#define ER_KTextBox_CannotMemAlloc	-2	/* ���������m�ۂł��܂��� */
										/* Can not allocate memory error. */
#define ER_KTextBox_NotFound		-3	/* �T�[�`�Ώۂ�������܂��� */
										/* Cannot find searched object error. */
#define ER_KTextBox_BadCharCode		-4	/* �����R�[�h���s���ł� */
										/* Illegal character code error. */
#define ER_KTextBox_BadFontFile		-5	/* �t�H���g�t�@�C�����s���ł� */
										/* Invalid font file error. */
#define ER_KTextBox_CannotOpenDS	-6	/* �f�B�X�N�X�g���[�����I�[�v���ł��܂��� */
										/* Cannot open disk stream error. */

#endif /* _KTEXTBOXERROR_H */
