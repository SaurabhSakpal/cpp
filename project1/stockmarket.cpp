#include <stock.h>
#include <trnx_error.h>
#include <string>
#include <iostream>

namespace BloombergLP {
namespace trnx {

  void StockMarket::addStockIndex(StockIndex* indexPtr) {
     m_indexArr[m_currentIndex] = indexPtr;
    ++m_currentIndex;
  }

  StockIndex * StockMarket::getStockIndex(const std::string& indexName, Error& error) const {
    for(int i = 0; i != m_currentIndex; ++i) {
      if(indexName == m_indexArr[i]->getIndexName()) {
          return m_indexArr[i];
      }
    }
    error.setError("Stock not present");
    return NULL;
  }

}
}
