#include <stock.h>
#include <trnx_error.h>
#include <iostream>
#include <string>

using namespace BloombergLP::trnx;
int main() {
  StockMarket market;
  StockTicker ticker("APPL US Equity", 41, 234);
  StockIndex* dowIndex = new StockIndex("DOW Index");
  StockIndex* induIndex = new StockIndex("INDU Index");
  StockIndex* spxIndex = new StockIndex("SPX Index");

  std::cout << "Hello World \n";
  std::cout << ticker;
  market.addStockIndex(dowIndex);
  market.addStockIndex(induIndex);
  market.addStockIndex(spxIndex);
  Error e;
  StockIndex* temp = market.getStockIndex("SPX Index", e);
  if(!e.isErrorPresent())
    std::cout << temp->getIndexName() << "\n";

}
