
#include<iostream>
using namespace std;
//
//unsigned char my_cards[] = {
//	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,						//����
//	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,						//����
//	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,						//����
//	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,						//����
//	0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,						//����
//	0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,						//����
//	0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,						//����
//	0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,						//����
//	0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,						//ͬ��
//	0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,						//ͬ��
//	0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,						//ͬ��
//	0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,						//ͬ��
//	0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,									//�����ϱ��з���
//	0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,									//�����ϱ��з���
//	0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,									//�����ϱ��з���
//	0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,									//�����ϱ��з���
//};
//
//void setLaiZi____________(){
//	cout << "�淨��������ӳɹ���" << endl;
//}
//
////playerNum : �������   , notWind:������ ,   laiZi:���л���,    queMen:ȱ��
//void printSetCfg(int playerNum, bool notWind, bool laiZi, bool queMen){
//	cout << "�������:" << playerNum << " ,�����磺" << notWind << " ,���л��ƣ�" << laiZi << " , " << "ȱ�ţ�" << queMen << endl;
//}
//
//void printCards_111(unsigned char cards[], int n){
//	for (int i = 0; i<n; i++){
//		printf("0x%-2x ", cards[i]);
//		if ((i + 1) % 9 == 0)
//			putchar(10);
//	}
//	putchar(10);
//}
//
////playerNum : �������   , notWind:������ ,   laiZi:���л���,    queMen:ȱ��
//int getPokerCards(unsigned char tmpCards[136], int playerNum, bool notWind, bool laiZi, bool queMen){
//
//	memset(tmpCards, 0, 136);
//	printSetCfg(playerNum, notWind, laiZi, queMen);
//
//	int cardsCount = 0;
//
//	//���������4 �� ���� 
//	if ((playerNum == 4) && (notWind == false))
//	{
//		cardsCount = 136;
//		memcpy(tmpCards, my_cards, 136);
//		if (laiZi)  //���л���
//			setLaiZi____________();
//		return cardsCount;
//	}
//
//	//���������4 �� ������ 
//	if ((playerNum == 4) && (notWind == true))
//	{
//		cardsCount = 108;
//		memcpy(tmpCards, my_cards, 108);
//
//		if (laiZi == true)//���л��� , 112 = 108 +4
//		{
//			for (int i = 0; i<4; i++)
//				tmpCards[108 + i] = 0x35;
//			setLaiZi____________();
//			cardsCount += 4;
//		}
//		return cardsCount;
//	}
//
//
//	//���������3 �� ���� 
//	if ((playerNum == 3) && (notWind == false))
//	{
//		//ȱ��
//		if (queMen == true)
//		{
//			cardsCount = 100;
//			memcpy(tmpCards, my_cards + 36, cardsCount);
//			if (laiZi == true)
//				setLaiZi____________();
//			return cardsCount;
//		}
//
//		//��ȱ��
//		else if (queMen == false)
//		{
//			cardsCount = 136;
//			memcpy(tmpCards, my_cards, cardsCount);
//			if (laiZi)
//				setLaiZi____________();
//			return cardsCount;
//		}
//	}
//
//	//���������3 �� ������ 
//	if ((playerNum == 3) && (notWind == true))
//	{
//		//ȱ��
//		if (queMen == true)
//		{
//			cardsCount = 72;
//			memcpy(tmpCards, my_cards + 36, 72);
//
//			if (laiZi == true)
//			{
//				for (int i = 0; i<4; i++)
//					tmpCards[72 + i] = 0x35;
//				setLaiZi____________();
//				cardsCount += 4;
//			}
//			return cardsCount;
//		}
//
//		//��ȱ��
//		else if (queMen == false)
//		{
//			cardsCount = 108;
//			memcpy(tmpCards, my_cards, 108);
//
//			if (laiZi == true)
//			{
//				for (int i = 0; i<4; i++)
//					tmpCards[108 + i] = 0x35;
//				setLaiZi____________();
//				cardsCount += 4;
//			}
//			return cardsCount;
//		}
//	}
//}
//
//
//void getPokerCards_test(){
//	int playerNum = 4;//�������
//	bool notWind = 1;//������
//	bool laiZi = 1;//���л���
//	bool queMen = 0;//ȱ��
//
//	unsigned char tmpCards[136];
//	memcpy(tmpCards, my_cards, 136);
//	int num = getPokerCards(tmpCards, playerNum, notWind, laiZi, queMen);
//	printCards_111(tmpCards, num);
//	cout << "��ǰ�淨�У��˿�����Ϊ��" << num << endl;
//
//
//}