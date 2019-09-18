
#pragma once

#include <iostream>
#include <list>
using namespace std;

typedef int INT;
typedef unsigned char BYTE;
typedef unsigned short WORD;


//�߼�����
#define	MASK_COLOR					0xF0								//��ɫ����
#define	MASK_VALUE					0x0F								//��ֵ����


//������־
#define WIK_NULL					0x00000								//û������
#define WIK_LEFT					0x00001								//������ͣ�������
#define WIK_CENTER					0x00002								//�г����ͣ�������
#define WIK_RIGHT					0x00004								//�ҳ�����
#define WIK_PENG					0x00008								//��������
#define WIK_MING_GANG				0x00010								//����
#define WIK_AN_GANG					0x00020								//����
#define WIK_BU_GANG					0x00040								//����
#define WIK_CHI_HU					0x00100								//�Ժ����ͣ����ڣ�
#define WIK_ZI_MO					0x00200								//���� 

#define WIK_SI_GUI_HU    			0x00400								//����4�Ź����

#define WIK_DUO_PAO					0x00800								//һ�ڶ��� ��̨����
#define WIK_HENG_YIJIU				0x01000							    //��һ��� ��̨����
#define WIK_YIJIU					0x02000								//һ�� ��̨����
#define WIK_GEN_Z    				0x04000								//���мҸ�ׯ����
//#define WIK_SI_GUI_HU			    0x04000                              // ����4�Ź����


//��������
#define CHR_NULL					0x0000										//�Ǻ�����
#define CHR_CHI_HU					0x0001										//ƽ��
#define CHR_GANG_HUA				0x0002							         	//���Ͽ���   
#define CHR_QIANG_GANG_HU			0x0004							        	//���ܺ�	 			
#define CHR_QI_XIAO_DUI				0x0008										//��С��	              
#define CHR_PENGPENG				0x0010										//������					
#define CHR_QING_YI_SE		     	0x0020										//��һɫ				
#define CHR_HAIDI_LAOYUE			0x0040										//��������					
#define CHR_KA_ZHANG				0x0080										//����  					
#define CHR_HUN_YI_SE		     	0x0400										//��һɫ
#define CHR_QING_FENG    			0x0800										//����
#define CHR_YI_TIAO_LONG			0x1000										//һ����
#define CHR_DAN_HAOHUA_QIDUI		0x2000										//�������߶�
#define CHR_SHUANG_HAOHUA_QIDUI		0x4000										//˫�����߶�
#define CHR_SAN_HAOHUA_QIDUI		0x8000										//�������߶�
#define CHR_SHI_SAN_YAO				0x10000			

#pragma pack(1)
//��������
struct tagKindItem
{
	INT								cbWeaveKind;						//�������
	BYTE							cbCenterCard;						//�����˿�
	BYTE							cbCardIndex[3];						//�˿�����
	BYTE							cbValidIndex[3];					//ʵ���˿�����
};

//�������
struct tagWeaveItem
{
	INT								cbWeaveKind;						//�������
	BYTE							cbCenterCard;						//�����˿�
	BYTE							cbPublicCard;						//������־
	WORD							wProvideUser;						//��Ӧ�û�
};

//���ƽ��
struct tagGangCardResult
{
	BYTE							cbCardCount;						//�˿���Ŀ
	BYTE							cbCardData[4];						//�˿�����
};

//��������
struct tagAnalyseItem
{
	BYTE							cbCardEye;							//�����˿�
	bool                            bMagicEye;                          //�����Ƿ�������
	INT								cbWeaveKind[4];						//�������
	BYTE							cbCenterCard[4];					//�����˿�
	BYTE                            cbCardData[4][4];                   //ʵ���˿�
};

