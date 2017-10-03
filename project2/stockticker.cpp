#include <stock.h>
#include <iostream>

namespace BloombergLP {
namespace trnx {

  std::ostream& operator<<(std::ostream& cout, const StockTicker& ticker) {
    cout << "Ticker Name: " << ticker.getTickerName() << "\n" << "Price: " << ticker.getPrice() << "\n" << "Quantity: " << ticker.getQuantity() << "\n";
    return cout;
  }

}
}
