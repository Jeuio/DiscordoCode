//
// Created by jeuio on 15/06/2022.
//

#pragma once

#include <Custom/Networking.h>

enum MessageIDs {

    NONE = 0,
    ECC_POINT_X, ECC_POINT_Y
};

class Authentication : public MessageHandler {

    BigNum privateKey;
    ECC::ECPoint privatePoint, B;
    bool privatePointGenerated = false; // This is not needed until multiple threads can act on this instance

    void onConnected() override;

    void onMessageReceived(Message message) override;

    void sendPrivatePoint();

    void deriveSessionKey();

public:

    [[nodiscard]] MessageHandler* clone() const override;

    Authentication();
};