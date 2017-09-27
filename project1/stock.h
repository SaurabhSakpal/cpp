#ifndef TRNX_STOCK
#define TRNX_STOCK

#include <trnx_error.h>
#include <string>


namespace BloombergLP {
namespace trnx {

  class StockTicker {
  private:
    std::string d_tickerName;
    unsigned long d_price;
    unsigned long d_quantity;

  public:
    StockTicker(const std::string& name, unsigned long price,unsigned quantity): d_tickerName(name), d_price(price), d_quantity(quantity) {};
    const std::string& getTickerName() const;
    const unsigned long& getPrice() const;
    const unsigned long& getQuantity() const;
  };

  class StockIndex {
  private:
    std::string d_indexName;

  public:
    explicit StockIndex(const std::string& name): d_indexName(name) {}
    const std::string& getIndexName();
    void addTicker();
    void printIndex();
    void removeTicker();
    void getTicker();
  };

  class StockMarket {
  private:
    enum {
      MAX_SIZE = 10
    };
    unsigned m_currentIndex;
    StockIndex* m_indexArr[MAX_SIZE];

  public:
    StockMarket():m_currentIndex(0) {}
    void addStockIndex(StockIndex* index);
    StockIndex* getStockIndex(const std::string& indexName, Error& error) const;
  };

  inline
  const std::string& StockTicker::getTickerName() const {
    return d_tickerName;
  }

  inline
  const unsigned long& StockTicker::getPrice() const {
    return d_price;
  }

  inline
  const unsigned long& StockTicker::getQuantity() const {
    return d_quantity;
  }

  inline
  const std::string& StockIndex::getIndexName() {
    return d_indexName;
  }

  std::ostream& operator<<(std::ostream& cout, const StockTicker& ticker);

}
}

#endif
