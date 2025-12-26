#include <iostream>
#include <string>
#include <vector>

enum class MenuOption
{
    PRINT_HELP = 1,
    PRINT_EXCHANGE_STATS = 2,
    MAKE_OFFER = 3,
    MAKE_BID = 4,
    PRINT_WALLET = 5,
    CONTINUE = 6,
    END_PROGRAM = 7
};
enum class OrderBookType { BID, ASK };

class OrderBookEntry
{
    public:
        OrderBookEntry
        (
            double price,
            double amount,
            std::string timestamp,
            std::string product,
            OrderBookType order_type
        ) :
            m_price { price },
            m_amount { amount },
            m_timestamp { timestamp },
            m_product { product },
            m_order_type { order_type } {}

    private:
        double m_price;
        double m_amount;
        std::string m_timestamp;
        std::string m_product;
        OrderBookType m_order_type;
};

void print_menu();
int get_user_option();
void handle_option(MenuOption choice, bool *is_running);
void print_help();
void print_exchange_stats();
void make_offer();
void make_bid();
void print_wallet();

/**
 * Main.
 */
int main()
{
    std::vector<double> prices;
    std::vector<double> amounts;
    std::vector<std::string> timestamps;
    std::vector<std::string> products;
    std::vector<OrderBookType> order_types;

    prices.push_back(5319.450228);
    amounts.push_back(5319.450228);
    timestamps.push_back("17:01:24.884492");
    products.push_back("BTC/USDT");
    order_types.push_back(OrderBookType::BID);

    bool is_running = true;

    OrderBookEntry order_1;

    while (is_running)
    {
        int user_option;

        print_menu();
        user_option = get_user_option();

        Menu_Option choice = static_cast<Menu_Option>(user_option);

        handle_option(choice, &is_running);
    }

    return 0;
}

void print_menu()
{
    std::cout << "1: Print help\n";
    std::cout << "2: Print exchange stats\n";
    std::cout << "3: Make an offer\n";
    std::cout << "4: Make a bid\n";
    std::cout << "5: Print wallet\n";
    std::cout << "6: Continue\n";
    std::cout << "7: End Program\n";

    std::cout << "===================\n";
    std::cout << "Type in 1-7: ";
}

int get_user_option()
{
    int user_option;

    std::cin >> user_option;
    std::cout << "You chose: " << user_option << "\n";
    std::cout << "===================\n";

    return user_option;
}

void handle_option(MenuOption choice, bool *is_running)
{
    switch (choice)
    {
        case MenuOption::PRINT_HELP:
            print_help();

            break;
        case MenuOption::PRINT_EXCHANGE_STATS:
            print_exchange_stats();

            break;
        case MenuOption::MAKE_OFFER:
            make_offer();

            break;
        case MenuOption::MAKE_BID:
            make_bid();

            break;
        case MenuOption::PRINT_WALLET:
            print_wallet();

            break;
        case MenuOption::CONTINUE:
            break;
        case MenuOption::END_PROGRAM:
            *is_running = false;

            break;
        default:
            std::cout << "Invalid choice. Choose 1-6\n";
    }
}

void print_help()
{
    std::cout << "Your aim is to make money. "
              << "Analyse the market and make bids "
              << "and offers.\n";
}

void print_exchange_stats()
{

}

void make_offer()
{

}

void make_bid()
{

}

void print_wallet()
{

}
