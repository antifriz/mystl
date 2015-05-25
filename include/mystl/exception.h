//
// Created by ivan on 5/22/15.
//

#ifndef _MYSTL_EXCEPTION_H
#define _MYSTL_EXCEPTION_H

#include <vector>
#include <string>

namespace mystd {


    class exception {
    protected:
        int err_num_;
        std::vector <std::string> msgs_;
    public:
        exception(int err_num, const std::string &msg) : err_num_(err_num) {
            msgs_.push_back(msg);
        }

        int err_num() const { return err_num_; }

        const std::string str() const {
            std::string str = "error ";
            for(unsigned int i =0;i<msgs_.size();i++){

            //for (std::vector<std::string>::const_iterator it = msgs_.begin(); it != msgs_.end(); it++) {

                str += "in ";
                str += msgs_[i];//*it;
                str += ", ";
            }
            return str;
        }

        const char *c_str() const {
            return str().c_str();
        }

        void append_msg(const std::string &msg) {
            msgs_.push_back(msg);
        }


    };
}


#endif //_MYSTL_EXCEPTION_H
