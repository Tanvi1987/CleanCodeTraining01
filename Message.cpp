#include <string>
#include <iostream>

using namespace std;

class EncryptionAlgorithm
{
public:
    virtual string encrypt(const string& data) = 0;
    virtual string decrypt(const string& data) = 0;
};

class AesEncryptionAlgorithm final : public EncryptionAlgorithm
{
public:
    string encrypt(const string& data)
    {
        cout << "Encrypting data using AES algorithm" << endl;
        /*Code to encrypt data using AES algorithm*/
        return "Aes";
    }

    virtual string decrypt(const string& data)
    {
        cout << "Decrypting cipher using AES algorithm" << endl;
        /*Code to decrypt data using AES algorithm*/
        return "Aes";
    }
};

class BlowfishEncryptionAlgorithm final : public EncryptionAlgorithm
{
public:
    string encrypt(const string& data)
    {
        cout << "Encrypting data using Blowfish algorithm";
        /*Code to encrypt data using Blowfish algorithm*/
        return "Blowfish";
    }

    string decrypt(const string& data)
    {
        cout << "Decrypting cipher using Blowfish algorithm";
        /*Code to decrypt data using Blowfish algorithm*/
        return "Blowfish";
    }
};

class Message
{
private:
    EncryptionAlgorithm *mAlgo;
    string text;

public :
    Message(EncryptionAlgorithm * algo) : mAlgo(algo) {}

    ~Message() { delete mAlgo; }

    string getText() const
    {
        return mAlgo->decrypt(text);
    }

    void setText(const string& data)
    {
        text = mAlgo->encrypt(data);
    }
};

int main()
{
    Message m(new AesEncryptionAlgorithm());
    m.setText("Some Text");
    cout << m.getText() << endl;
}
