#ifndef TRNX_ERROR
#define TRNX_ERROR

#include <string>

namespace BloombergLP {
namespace trnx {

  /**
    Error Class for simple error handling
  */
  class Error {
    private:
      std::string d_message;
        // Error Message string

      bool d_isPresent;
        // Flag to determine if Error obj represents a valid Error

    public:
      Error():d_message(""), d_isPresent(false) {};
        // Default constructor to create dummy Error object

      const std::string& getErrorMessage() const;
        // Default constructor

      const bool& isErrorPresent() const;
        // Returns if this Error obect returns a valid Error

      void setError(const std::string& message);
        // Sets error message and also the is error flag
  };

  inline
  void Error::setError(const std::string& message) {
    d_message = message;
    d_isPresent = true;
  }

  inline
  const std::string& Error::getErrorMessage() const {
    return d_message;
  }

  inline
  const bool& Error::isErrorPresent() const {
    return d_isPresent;
  }
}
}

#endif
