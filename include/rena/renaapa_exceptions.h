#ifndef __RENALIBS_RENAAPA_EXCEPTIONS_H__
#define __RENALIBS_RENAAPA_EXCEPTIONS_H__

#include<exception>
#include<sstream>
#include<string>

namespace rena::exceptions {

    template<typename T>
    class renaapa_basic_exception : public std::exception {

        public:
            renaapa_basic_exception( unsigned int __ui_errcode , std::string __s_errmsg ) : _ui_errcode( __ui_errcode ) {
                std::ostringstream oss;
                oss << "[" << this -> ExceptionTypeName << ":" << this -> _ui_errcode << "] " << __s_errmsg;
                this -> _s_errmsg = oss.str();
                return;
            }
            virtual ~renaapa_basic_exception() noexcept {}

            virtual const char* what() const noexcept {
                return this -> _s_errmsg.c_str();
            };

            unsigned int code() const noexcept {
                return this -> _ui_errcode;
            }

            static constexpr const char* ExceptionTypeName = T::ExceptionTypeName;

        private:
            unsigned int _ui_errcode;
            std::string _s_errmsg;

    }; // class renaapa_basic_exception

    class renaapa_illegal_value : public renaapa_basic_exception<renaapa_illegal_value> {

        public:
            renaapa_illegal_value( unsigned int __ui_errcode , std::string __s_errmsg )
                : renaapa_basic_exception<renaapa_illegal_value>( __ui_errcode , __s_errmsg ) {}
            virtual ~renaapa_illegal_value() noexcept {}

            static constexpr const char* ExceptionTypeName = "renaapa_illegal_value";

    }; // class renaapa_illegal_value

    class renaapa_out_of_range : public renaapa_basic_exception<renaapa_out_of_range> {

        public:
            renaapa_out_of_range( unsigned int __ui_errcode , std::string __s_errmsg )
                : renaapa_basic_exception<renaapa_out_of_range>( __ui_errcode , __s_errmsg ) {}
            virtual ~renaapa_out_of_range() noexcept {}

            static constexpr const char* ExceptionTypeName = "renaapa_out_of_range";

    }; // class renaapa_out_of_range

} // namespace rena::exceptions

#endif // __RENALIBS_RENAAPA_EXCEPTIONS_H__
