#include "book_info_deref.h" // for bookInfoDeref

vector<bookType> bookInfoDeref(vector<bookType*> &bookInfo)
{
    vector<bookType> derefBookInfo;
    for (size_t i = 0; i < bookInfo.size(); ++i)
    {
        derefBookInfo.push_back(*bookInfo[i]);
    }
    return derefBookInfo;
}