
#include <vector>

#include <iostream>
using namespace std;

#include "hu_type.h"

typedef unsigned char BYTE;
#define MAX_INDEX 34

#define MAX_TING 19
#define GAME_PLAYER 4
#define MAX_COUNT 14

BYTE m_OutCardData[GAME_PLAYER][MAX_COUNT];            //������ļ�����
BYTE m_TingCardCount[GAME_PLAYER][MAX_COUNT];          //���Ӧ����ƿ����Ƹ�����������ʾ�ڼ��ţ�ֵ�Ƕ�Ӧ��Ӧ�����Ƹ���
WORD m_TingCardData[GAME_PLAYER][MAX_COUNT][MAX_TING]; //�����������ݣ�һά������ʾ����Ƶĵڼ�������ά������ʾ���Ƶĵڼ�����ֵ��ʾ������

bool AnalyseChiHuCard(const BYTE cbCardIndex[MAX_INDEX])
{
    if (cbCardIndex[31] == 4)
        return true;

    if (hu_type::check_hu(cbCardIndex, 31))
        return true;
    return false;
}

bool AnalyseTingCard(const BYTE cbCardIndex[MAX_INDEX], vector<BYTE> &ting_list)
{
    BYTE cbCardCount = 0;
    BYTE cbCardIndexTemp[MAX_INDEX];
    memcpy(cbCardIndexTemp, cbCardIndex, sizeof(cbCardIndexTemp));

    for (int i = 0; i < MAX_INDEX; i++)
        cbCardCount += cbCardIndex[i];

    if (cbCardCount % 3 != 1)
        return false;

    bool IsHu = false;
    for (BYTE i = 0; i < MAX_INDEX; i++)
    {
        cbCardIndexTemp[i]++;
        if (AnalyseChiHuCard(cbCardIndexTemp))
        {
            ting_list.push_back(i);
            IsHu = true;
        }
        cbCardIndexTemp[i]--;
    }
    return IsHu;
}

bool OutTingCard(WORD wChairID, BYTE cardIndex, BYTE Hand[])
{
    memset(m_OutCardData[wChairID], 0, sizeof(m_OutCardData[wChairID]));     //������ļ�����
    memset(m_TingCardCount[wChairID], 0, sizeof(m_TingCardCount[wChairID])); //���Ӧ����ƿ����Ƹ�����������ʾ�ڼ��ţ�ֵ�Ƕ�Ӧ��Ӧ�����Ƹ���
    memset(m_TingCardData[wChairID], 0, sizeof(m_TingCardData[wChairID]));   //�����������ݣ�һά������ʾ����Ƶĵڼ�������ά������ʾ���Ƶĵڼ�����ֵ��ʾ������

    BYTE ting_num = 0;
    vector<BYTE> ting_list;

    if (AnalyseTingCard(Hand, ting_list) == false)
        return false;

    for (auto i : ting_list)
    {
        if (i < 27 || i == 31)
        {
            //m_TingCardData[wChairID][0][ting_num++] = m_GameLogic.SwitchToCardData(j);
            //BYTE num = RemainNum(wChairID, (const BYTE)m_TingCardData[wChairID][0][ting_num - 1], cardIndex);
            //m_TingCardData[wChairID][0][ting_num - 1] = m_GameLogic.GetValue(num, m_cbTingPai[j], m_TingCardData[wChairID][0][ting_num - 1]);

            //if (ting_num >= MAX_TING)
            //{
            //	m_TingCardCount[wChairID][0] = 255;
            //	memset(m_TingCardData[wChairID][0],0, ting_num);
            //	break;
            //}

            ting_num++;
            printf("%d ", i);
        }
    }

    return true;
}


void ting_test(){
	BYTE cards0[34] = {
		3, 1, 1, 1, 1, 1, 1, 1, 3,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0,
	};

	BYTE cards2[34] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 1, 0, 2, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0,
	};

	BYTE cards[34] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 2, 0, 0,
	};
	
	OutTingCard(0, 33,cards);
}
