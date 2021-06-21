#ifndef CFANUCBOTSOCKET_H
#define CFANUCBOTSOCKET_H

#include "cabstractbotsocket.h"
#include "fanucsocket.h"

class CFanucBotSocket:
        public QObject,
        public CAbstractBotSocket
{
    Q_OBJECT
public:
    CFanucBotSocket() = default;

    BotSocket::TSocketError startSocket();
    void stopSocket();
    BotSocket::TSocketState socketState() const;

private slots:
    void slot_position_received(struct FanucSocket::position pos);
    void slot_state_changed();

private:
    bool active_ = false;
    FanucSocket fanuc_socket_;
};

#endif // CFANUCBOTSOCKET_H
