#ifndef BITTREX_CPP_CLIENT_H
#define BITTREX_CPP_CLIENT_H

#include <iostream>
#include <memory>
#include "connection.h"
#include "api/public.h"
#include "api/market.h"
#include "api/account.h"

namespace bittrex {

class Client {
public:
    explicit Client(const std::string &key, const std::string &secret) :
            m_connection(make_unique<Connection>(key, secret)) {}

    /**
     * Used for public information available without an API key
     */
    api::Public public_api();

    /**
     * Used for programatic trading of crypto currencies
     */
    api::Market market_api();

    /**
     * Used for managing your account
     */
    api::Account account_api();


private:
    std::unique_ptr<Connection> m_connection;
};
}
#endif //BITTREX_CPP_CLIENT_H
