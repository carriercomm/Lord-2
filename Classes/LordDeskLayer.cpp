//
//  LordDeskLayer.cpp
//  MyCppGame
//
//  Created by Apple mac on 15/3/15.
//
//

#include "LordDeskLayer.h"
#include "Card.h"


LordDeskLayer::LordDeskLayer()
{
    m_player0 = NULL;
    m_player1 = NULL;
    m_player2 = NULL;
}

LordDeskLayer::~LordDeskLayer()
{
    CC_SAFE_DELETE(m_mediator);
    
}

bool LordDeskLayer::init()
{
    
    m_mediator = new LordMediator();
    
    m_player0 = Player::create(0);
    m_player2 = Player::create(2);
    m_player1 = Player::create(1);
    
    
    for (int i = 0; i < CARD_TOTAL ; i++) {
        m_deskPokes[i] = i;
    }
    
    //洗牌
    m_mediator->suffle(m_deskPokes, CARD_TOTAL);
    //分牌
    fenpai();
    
    randDZ();
    
    return true;
}

void LordDeskLayer::onEnter()
{
    Node::onEnter();
    Node* playNode0 = dynamic_cast<Node*>(getVariable<Node>("playNode0"));
    Node* playNode1 = dynamic_cast<Node*>(getVariable<Node>("playNode1"));
    Node* playNode2 = dynamic_cast<Node*>(getVariable<Node>("playNode2"));
    
    m_player0->setCardList(m_personPokes[0]);
    m_player1->setCardList(m_personPokes[1]);
    m_player2->setCardList(m_personPokes[2]);
    
    
    if (playNode0 != NULL) {
        playNode0->addChild(m_player0,5);
    }
    
    if (playNode1 != NULL) {
        playNode1->addChild(m_player1,5);
    }
    
    if (m_player2 != NULL) {
        playNode2->addChild(m_player2,5);
    }
}

void LordDeskLayer::onExit()
{
    Node::onExit();
}


void LordDeskLayer::fenpai() {
    int perIndex = 0;
    int cardIndex = 0;
    for (int i = 0; i < 51;) {
        perIndex = int(i/17);
        cardIndex = int(i%17);
        m_personPokes[perIndex].push_back(m_deskPokes[i++]);
    }
    
    m_threePokes[0] = m_deskPokes[51];
    m_threePokes[1] = m_deskPokes[52];
    m_threePokes[2] = m_deskPokes[53];
}

void LordDeskLayer::randDZ()
{
    int boss = m_mediator->getDZ();
    this->m_boss = boss;
//    int *newPersonPokes = new int[20];
//    for (int i = 0; i < 17; i++) {
//        newPersonPokes[i] = m_personPokes[boss][i];
//    }
//    newPersonPokes[17] = m_threePokes[0];
//    newPersonPokes[18] = m_threePokes[1];
//    newPersonPokes[19] = m_threePokes[2];
//    
//    m_personPokes[boss].clear();
//    for (int j = 0; j<20; j++) {
//        m_personPokes[boss].push_back(newPersonPokes[j]);
//    }
}