/* Copyright (c) 2018-2019 Sigmastar Technology Corp.
 All rights reserved.
  
  Unless otherwise stipulated in writing, any and all information contained
 herein regardless in any format shall remain the sole proprietary of
 Sigmastar Technology Corp. and be kept in strict confidence
 (??Sigmastar Confidential Information??) by the recipient.
 Any unauthorized act including without limitation unauthorized disclosure,
 copying, use, reproduction, sale, distribution, modification, disassembling,
 reverse engineering and compiling of the contents of Sigmastar Confidential
 Information is unlawful and strictly prohibited. Sigmastar hereby reserves the
 rights to any and all damages, losses, costs and expenses resulting therefrom.
*/
#ifndef __MI_OSD_H__
#define __MI_OSD_H__
#ifdef __cplusplus
extern "C"
{
#endif

#include "mi_common.h"
#include "mi_video_type.h"

/*
 * user widget attr
 */
typedef void* UserData_t;       //�û��Զ���ͼ�ε�����

/**
 * �û���Ҫ���Զ���ͼ�ε�callback��������
 * pUserData: �û��Զ��������
 * dstYBuf::  �ṩ���û�������Y bufferָ��
 * dstUVBuf:  �ṩ���û�������UV bufferָ��
 * dstWidth:  ���������ؿ��
 * dstHeight: ���������ظ߶�
 */
typedef void (*UserOsdCallback_t)(UserData_t pUserData, U8* dstYBuf, U8 *dstUVBuf, U32 dstWidth, U32 dstHeight);

/**
* font pixel type
*/
typedef enum _OsdFontSize_e
{
    FONT_SIZE_32,
    FONT_SIZE_64,
    FONT_SIZE_24,
    FONT_SIZE_16
} OsdFontSize_e;




typedef enum
{
    FB_PIXEL_ALPHA = 0,
    FB_CONST_ALPHA = 1,
} FbAlphaType_e;

/**
 * Alpha config
 */
typedef struct _FbAlphaConfig_t
{
    U8 enable;
    FbAlphaType_e alphaType;
    U8 alpha;
} FbAlphaConfig_t;

typedef struct
{
    /// RGBA888
    U8 u8B;
    U8 u8G;
    U8 u8R;
    U8 u8A;
} OsdPaletteEntry_t;

typedef struct _OsdPalette_t
{
    OsdPaletteEntry_t entry[256];
} OsdPalette_t;


typedef struct OsdInvertColor_s
{
    U32  nLumThresh;                //The threshold to decide whether invert the OSD's color or not.
    BOOL bInvColEn;                  //The switch of inverting color.
} OsdInvertColor_t;

typedef struct yuvWidgetAttr_s
{
    void* buf;
    U32 bufSize;
    Point_t* pPoint;
    U32 width;
    U32 height;
    BOOL bRle;
    BOOL bOutline;
} yuvWidgetAttr_t;



typedef struct textWidgetAttr_s
{
    char * string;
    Point_t* pPoint;
    OsdFontSize_e size;
    Color_t* pfColor;
    Color_t* pbColor;
    U32 space;
    BOOL bHard;
    BOOL bRle;
    BOOL bOutline ;
} textWidgetAttr_t;
typedef struct userWidgetAttr_s
{
    UserData_t pUserData;   //�û��Զ��������
    U64 userDataSize;       //�û��Զ������ݵĴ�С
    UserOsdCallback_t callback; //�û���ͼ�ص�����
} userWidgetAttr_t;

/**
 * ��yuv�ַ�����ָ��vi chn
 * handle: ���ڻ�ȡ���صĿؼ����ָ��
 * viChn:   Ŀ��vi chn
 * string:  ��ʾ���ַ���
 * point: �ַ�����ʾ����ʼ��
 * size:    �ַ����Ĵ�С
 * fColor:   �ַ�������ɫ
 * bColor:   �ַ����ı�����ɫ
 * space:   �ַ�������ؼ��
 * return: MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_CreateTextWidget(MI_HANDLE *pHandle, VI_CHN viChn, const char * string, Point_t* pPoint, OsdFontSize_e size, Color_t* pfColor, Color_t* pbColor, U32 space , BOOL bHard);


/**
 * ��yuvͼ��ָ��vi chn
 * handle: ���ڻ�ȡ���صĿؼ����ָ��
 * viChn:   Ŀ��vi chn
 * buf:     YUVͼ��buffer
 * bufSize: YUVͼ��buffer�Ĵ�С
 * point: �ַ�����ʾ����ʼ��
 * width:   YUVͼ��Ŀ��
 * height:  YUVͼ��ĸ߶�
 * return: MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_CreateYuvWidget(MI_HANDLE *pHandle, VI_CHN viChn, void* buf, U32 bufSize, Point_t* pPoint, U32 width, U32 height);

/**
 * ��yuvͼ��ָ��vi chn
 * handle: ���ڻ�ȡ���صĿؼ����ָ��
 * viChn:   Ŀ��vi chn
 * pAttr:  ��������yuv widget�����Խṹ��
 * return: MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_CreateYuvWidgetEx(MI_HANDLE *pHandle, VI_CHN viChn, yuvWidgetAttr_t* pAttr);

/**
 * ��ָ����vi chn������
 * handle: ���ڻ�ȡ���صĿؼ����ָ��
 * viChn:   Ŀ��vi chn
 * rect: ���εĴ�С
 * color:   ���ο����ɫ
 * bFill:   �����ڲ��Ƿ����
 * return: MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_CreateRectWidget(MI_HANDLE *pHandle, VI_CHN viChn, Rect_t* pRect, Color_t* pColor, BOOL bFill);

/**
 * ��ָ����vi chn������
 * handle: ���ڻ�ȡ���صĿؼ����ָ��
 * viChn:   Ŀ��vi chn
 * rect: ���εĴ�С
 * color:   ���ο����ɫ
 * bFill:   �����ڲ��Ƿ����
 * bHard:   һ��ʹ��RECT_MODE_AUTO�������Ҫû����˽�ڵ���������Ƶ������ͨ�����벻Ҫ����-1ͨ���ľ��Σ�ͬʱָ��modeΪhard or soft��
 * return: MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_CreateRectWidgetEx(MI_HANDLE *pHandle, VI_CHN viChn, Rect_t* pRect, Color_t* pColor, BOOL bFill , BOOL bHard);


/**
 * �趨��Ҫ��ʾ��ͼƬbuffer��ͼƬ�ĸ�ʽrgb888 argb8888 argb1555 argb4444
 * handle: ���ڻ�ȡ���صĿؼ����ָ��
 * viChn:   Ŀ��vi chn
 * buf:  ͼƬ�ļ�·��
 * point:  ͼƬ��ʾ����ʼ��
 * pRoi:  ��ʾͼƬ������
 * return: MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */

MI_RET MI_OSD_CreateBitmapWidgetFromFile(MI_HANDLE *pHandle, VI_CHN viChn, const char* path, Point_t* pPoint, Rect_t *pRoi);

/**
 * �趨��Ҫ��ʾ��ͼƬbuffer��ͼƬ�ĸ�ʽrgb888 argb8888 argb1555 argb4444
 * handle: ���ڻ�ȡ���صĿؼ����ָ��
 * viChn:   Ŀ��vi chn
 * imageData:  ͼƬ����
 * point:  ͼƬ��ʾ����ʼ��
 * pRoi:  ��ʾͼƬ������
 * return: MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */

MI_RET MI_OSD_CreateBitmapWidget(MI_HANDLE *pHandle, VI_CHN viChn, ImageData_t* imageData, Point_t* pPoint, Rect_t *pRoi);

/**
 * ���Զ���ͼ����ָ��vi chn
 * handle:  ���ڻ�ȡ���صĿؼ����ָ��
 * viChn:   Ŀ��vi chn
 * pAttr��  ��������user widget�����Խṹ��
 * return: MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_CreateUserWidget(MI_HANDLE *pHandle, VI_CHN viChn, userWidgetAttr_t* pAttr);

/**
 * �����ַ����ؼ�������
 * handle: �ؼ��ľ��
 * viChn:   Ŀ��vi chn
 * string:  ��ʾ���ַ���
 * point: �ַ�����ʾ����ʼ��
 * size:    �ַ����Ĵ�С
 * fColor:   �ַ�������ɫ
 * bColor:   �ַ����ı�����ɫ
 * space:   �ַ�������ؼ��
 * return: MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
*/
MI_RET MI_OSD_UpdateTextWidget(MI_HANDLE handle, S8 * string, Point_t* pPoint, OsdFontSize_e size, Color_t* pfColor, Color_t* pbColor, U32 space);


/**
 * ����YUV�ؼ�������
 * handle: �ؼ��ľ��
 * viChn:   Ŀ��vi chn
 * buf:     YUVͼ��buffer
 * bufSize: YUVͼ��buffer�Ĵ�С
 * point: �ַ�����ʾ����ʼ��
 * width:   YUVͼ��Ŀ��
 * height:  YUVͼ��ĸ߶�
 * return: MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_UpdateYuvWidget(MI_HANDLE handle, void* buf, U32 bufSize, Point_t* pPoint, U32 width, U32 height);

/**
 * ��ָ����vi chn������
 * handle: �ؼ��ľ��
 * viChn:   Ŀ��vi chn
 * rect: ���εĴ�С
 * color:   ���ο����ɫ
 * bFill:   �����ڲ��Ƿ����
 * return: MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_UpdateRectWidget(MI_HANDLE handle, Rect_t* pRect, Color_t* pColor, BOOL bFill);

MI_RET MI_OSD_UpdateBitmapWidgetFromFile(MI_HANDLE handle, const char* path, Point_t* pPoint, Rect_t *pRoi);

/**
 * ������Ҫ��ʾ��ͼƬbuffer��ͼƬ�ĸ�ʽrgb888 argb8888 argb1555 argb4444
 * handle: ���ڻ�ȡ���صĿؼ����ָ��
 * viChn:   Ŀ��vi chn
 * imageData:  ͼƬ����
 * point:  ͼƬ��ʾ����ʼ��
 * pRoi:  ��ʾͼƬ������
 * return: MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_UpdateBitmapWidget(MI_HANDLE handle, ImageData_t* pImageData, Point_t* pPoint, Rect_t *pRoi);

/**
 * �����Զ���ͼ����ָ��vi chn
 * handle:  ���ڻ�ȡ���صĿؼ����ָ��
 * pAttr��  ��������user widget�����Խṹ��
 * return: MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_UpdateUserWidget(MI_HANDLE handle, userWidgetAttr_t* pAttr);
/***********************************OSD API define  *****************************************/

/**
 * ���ٿؼ�
 * handle: �ؼ����ָ��
 * return: MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_DestroyWidget(MI_HANDLE handle);

/**
 * ���¿ؼ�����ʾ����
 * handle: �ؼ��ľ��
 * viChn:   Ŀ��vi chn
 * visible:  �ؼ��Ƿ�ɼ�
 * return: MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
*/
MI_RET MI_OSD_SetWidgetVisible(MI_HANDLE handle, BOOL visible);


/**
 * �趨osd��alphaֵ
 * alphaConfig: alpha�趨
 * return:  MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_SetAlphaConfig(VI_CHN viChn, FbAlphaConfig_t* alphaConfig);

/**
 * ��ȡosd��alphaֵ
 * viChn:   Ŀ��vi chn
 * alphaConfig: alpha�趨
 * return:  MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_GetAlphaConfig(VI_CHN viChn, FbAlphaConfig_t *alphaConfig);


/**
 * �趨osd��color keyֵ
 * viChn:   Ŀ��vi chn
 * index:     color key�ڵ�ɫ���е�����ֵ
 * return:  MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_SetColorKeyConfig(VI_CHN viChn, U8 index);

/**
 * ��ȡosd��color keyֵ
 * viChn:   Ŀ��vi chn
 * index:     color key�ڵ�ɫ���е�����ֵ
 * return:  MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_GetColorKeyConfig(VI_CHN viChn, U8 *index);

/**
 * �趨osd��ɫ��
 * viChn:   Ŀ��vi chn
 * palette:     ��ɫ��
 * return:  MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_SetPalette(VI_CHN viChn, OsdPalette_t* palette);

/**
 * ��ȡosd�ĵ�ɫ��
 * viChn:   Ŀ��vi chn
 * palette:     ��ɫ��ĵ�ַ
 * return:  MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_GetPalette(VI_CHN viChn, OsdPalette_t *palette);

/**
 * ��ȡosd�ķ�ɫ����? * viChn:   Ŀ��vi chn
 * palette:     ��ɫ����
 * return:  MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_SetInvertColor(VI_CHN viChn, OsdInvertColor_t *invertColor);


/**
 * �趨osd�ķ�ɫ����
 * viChn:   Ŀ��vi chn
 * palette:     ��ɫ����
 * return:  MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_OSD_GetInvertColor(VI_CHN viChn, OsdInvertColor_t *invertColor);

/**
 * ����ͨ��OSD ��������ֵ����������ã�Ĭ���������涼����? * �������ֻ��Ҫ�ڻ�����Ϸ�����OSD,nHeight�Ϳ�������СһЩ
 * viChn:   Ŀ��vi chn
 * nWidth:     ��ȱ߽�
 * nHeight:     �߶ȱ߽�
 * return:  MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */

MI_RET MI_OSD_SetCanvasSize(VI_CHN ViChn , U32 nWidth , U32 Height);


/**
 * ʹ��ViChn ͨ����Widget ��ʾ��������
 * viChn:   Ŀ��vi chn
 * palette:     ��ɫ��ĵ�ַ
 * return:  MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */

MI_RET MI_OSD_UpdateCanvas(VI_CHN ViChn);


#ifdef __cplusplus
}
#endif


#endif //__MI_OSD_H__

