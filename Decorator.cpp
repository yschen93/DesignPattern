#include <iostream>
#include <string>
class Stream
{
public:
    virtual ~Stream() {}
    Stream(const std::string& name)
        :name_(name) {}
    virtual void read() = 0;
    virtual void write() = 0;
    virtual void seek() = 0;
protected:
    std::string name_;
};

class FileStream : public Stream
{
public:
    FileStream()
        :Stream("FileStream") {}
    void read() override
    {
        std::cout << "FileStream::read()" << "\n";
    }

    void write() override
    {
        std::cout << "FileStream()::write()" << "\n";
    }

    void seek() override
    {
        std::cout << "FileStream()::seek()" << "\n";
    }
};

class NetworkStream : public Stream
{
public:
    NetworkStream()
            :Stream("NetWorkStream") {}
    void read() override
    {
        std::cout << "NetworkStream::read()" << "\n";
    }

    void write() override
    {
        std::cout << "NetworkStream()::write()" << "\n";
    }

    void seek() override
    {
        std::cout << "NetworkStream()::seek()" << "\n";
    }
};

class Decorator : public Stream
{
public:
    virtual ~Decorator() {}
    Decorator() = default;
    Decorator(Stream* stream)
        :Stream("Decorator"), stream_(stream) {}
protected:
    Stream* stream_ {nullptr};
};

class DecryptStream : public Decorator
{
public:
    DecryptStream(Stream* stream)
        :Decorator(stream) {}
    void read() override
    {
        std::cout << "DecryptOperation" << "\n";
        stream_->read();
    }

    void write() override
    {
        std::cout << "DecryptOperation" << "\n";
        stream_->write();
    }

    void seek() override
    {
        std::cout << "DecryptOperation" << "\n";
        stream_->seek();
    }
};

int main(int argc, char* argv[])
{
    Stream* stream = new FileStream();
    Stream* stream1 = new DecryptStream(stream);
    stream1->read();
    return 0;
}