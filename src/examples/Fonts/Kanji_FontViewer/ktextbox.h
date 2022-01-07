#ifndef _KTEXTBOX_H
#define _KTEXTBOX_H

/******************************************************************************
**
**  $Id: ktextbox.h,v 1.4 1994/11/21 22:06:49 vertex Exp $
**
******************************************************************************/


#include "ktextbox_error.h"

#define justLeft 		0 /* ������ */
#define justRight 		1 /* �������� */
#define justCenter 		2 /* �E���� */
#define justJustify 		3 /* �ϓ����� */

#define SJIS_KANJI_HIGH(c)      (((0x81 <= (c)) && ((c) <= 0x9f)) || ((0xe0 <= (c)) && ((c) <= 0xfc)))
#define SJIS_KANJI_LOW(c)       (((0x40 <= (c)) && ((c) <= 0x7e)) || ((0x80 <= (c)) && ((c) <= 0xfc)))
#define SJIS_KANJI_LEVEL2(c)    ((0x989f <= (c)) && ((c) <= 0xeafc))
#define NUM_KANJI_LEVEL1    	3760

#define fg_Opaque		0x01 /* �����F�ɕs����������ݒ� */
#define bg_Opaque		0x02 /* �w�i�F�ɕs����������ݒ� */

typedef struct Rectf16 {
	frac16 rectf16_XLeft;
	frac16 rectf16_YTop;
	frac16 rectf16_XRight;
	frac16 rectf16_YBottom;
} Rectf16;

typedef struct 
{
    short	align;		/* ���񂹁A�����A�E��*/
						/* Text alignment (left, right, center). */
    int32	charPitch;	/* ���ԁi�h�b�g�P�ʁj*/
						/* Inter-character spacing. */
    int32	linePitch;	/* �s�ԁi�h�b�g�P�ʁj*/
						/* Spacing bewteen adjactent rows (leading). */
} TextAlign ;

typedef struct
{
    Rectf16		celRect;        /* �Z���̑傫�����w�� */
								/* Cel bounds. */
    Rectf16     wrapRect;       /* �e�L�X�g�`��̈���w�� */
								/* Bounds to wrap text into. */
    uint16      align;          /* �e�L�X�g�̑������̎w�� */
								/* Text alignment (left, right, center, justify). */
    int32       charPitch;      /* ���Ԃ��w�� */
								/* Inter-character spacing. */
    int32       linePitch;      /* �s�Ԃ��w�� */
								/* Spacing bewteen adjactent rows (leading). */
    Color       fgColor;        /* �����F���w�� */
								/* Foreground color (text color). */
    Color       bgColor;        /* �w�i�F���w�� */
								/* Background color (color beneath text). */
    uint8		opaqueFlag;		/* �s�����������w�� */
								/* Is the text background opaque? */
    uint8       otherFlags;     /* �\\�� */
								/* Reserved.  Set to NULL. */
    int32       reserved;     	/* �\\�� */
								/* Reserved.  Set to NULL. */
} KTextBox;

typedef struct {
    uint16     	nChars;			/* �܂܂�镶���R�[�h�̐�*/
								/* Number of characters. */
    uint16     	minCode;		/* �ŏ��̕����R�[�h*/
								/* Minimum character code. */
    uint16     	maxCode;		/* �ő�̕����R�[�h*/
								/* Maximum character code. */
    uint8		charHeight; 	/* �����̍���(pixels) */
								/* Character height (pixels). */
    uint8		charWidth; 		/* �����̕�(pixels) */
								/* Character width (pixels). */
    uint32		oneCharSize;	/* �P�����̃s�N�Z���f�[�^�̃o�C�g��(pad byte���܂�) */
								/* Size of one character bitmap in bytes (long-word aligned). */
    uint16		*codeTbl;		/* �����R�[�h�e�[�u���ւ̃|�C���^ */
								/* Optional character code table. */
    uint8		*widthTbl;		/* �σs�b�`���̕������e�[�u���ւ̃|�C���^ */
								/* Optional caracter width table. */
    char 		*charData;		/* �s�N�Z���f�[�^�̐擪�|�C���^*/
								/* Character bitmap data. */
} KFontRec;

typedef struct {
    uint8     	font_Gpp;			/* Gray scale bits per pixel*/
    uint8     	font_Bpp;			/* Bits per pixel */
    KFontRec	font_Hinfo;			/* ���p�����pFontRec�\\���� */
									/* Hankaku (half-width) character information. */
    KFontRec	font_Zinfo;			/* �S�p�����pFontRec�\\���� */
									/* Zenkaku (full-width) character information. */
	Stream*		font_fs;			/* Font file stream */
	Boolean		font_FullRead;		/* If true, read whole font image into memory. */
	uint32		font_HFSeekOffset;	/* File offset to Hankaku bitmap data. */
	uint32		font_ZFSeekOffset;	/* File offset to Zenkaku bitmap data. */
	Boolean		fsRead;				/* If true, use file system calls; otherwise, use low-level IO calls. */
	uint32		maxCharSize;		/* Maximum char size */
	IOInfo		romioInfo;			/* Internal use only. */
	Item		romIOReqItem;		/* Internal use only. */
	IOReq		*romior;			/* Internal use only. */
	uint32		logRomBlockSize;	/* Internal use only. */
} KFont3DO;

extern int32 KLoadFont(char *name, KFont3DO *theFont, Boolean fullRead );

extern int32 KFreeFont(KFont3DO *theFont);

extern CCB * KTextBox_A(KFont3DO *theFont, uint8 *theText, int32 textLen, Rectf16 *wrapBox, TextAlign *theAlign, Color fgColor, Color bgColor, CCB *userCCB);

extern int32 KTextBox_B(KFont3DO *theFont, KTextBox *theTextBox, uint8 *theText, int32 textLen, CCB **userCCB);

extern int32 KTextLength( uint8 *theText );

extern int32 KFreeCel( CCB *theCCB );

extern int32 KGetCharWidth(KFont3DO *theFont, uint16 charVal);

extern int32 KGetCharHeight(KFont3DO *theFont, uint16 charVal);

#endif /* _KTEXTBOX_H */
