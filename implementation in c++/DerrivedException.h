/* 
 * 
 * HW :    7
 * File:   DerrivedException.h
 * Author: Gulzada IISAEVA
 * ID:     131044085
 * 
 *
 * Exception icin exception classinan tureyen kendi sinifimi yazdim.Exception classinin virtual
 * fonskiyonlari implement ettim
 */

#ifndef DERRIVEDEXCEPTION_H
#define	DERRIVEDEXCEPTION_H

#include <exception>
#include <string>

using namespace std;
namespace myBigram {
class DerrivedException : public exception{
public:
    //DerrivedException()throw () :warning_message(string()) {};
    DerrivedException(const string& theMessage)throw () : warning_message(theMessage) {};
    virtual const char* what () const throw () { return warning_message.c_str();}; //c_str stringi const chara cevirir
    virtual ~DerrivedException() throw () {} ;
            
private:
    string warning_message;
};

}
#endif	/* DERRIVEDEXCEPTION_H */
