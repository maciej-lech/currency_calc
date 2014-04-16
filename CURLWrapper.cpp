#include "CURLWrapper.h"

CURL* CURLWrapper::handle = NULL;
std::string CURLWrapper::data;

CURLWrapper::CURLWrapper()
{
    curl_global_init(CURL_GLOBAL_ALL);
	handle = curl_easy_init();
}

CURLWrapper::~CURLWrapper()
{
    if (handle)
        curl_easy_cleanup(handle);

	curl_global_cleanup();
}

int CURLWrapper::curlWriteMemoryCallback(void *contents, size_t size, size_t blocks, void *mem_data)
{
    size_t real_size = size * blocks;
    data.append((const char*) contents, real_size);

    return real_size;
}

int CURLWrapper::downloadData(const std::string& url)
{
    if (!handle)
        return 1;

    data.clear();

	curl_easy_setopt(handle, CURLOPT_URL, url.c_str());
	curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, curlWriteMemoryCallback);
	//curl_easy_setopt(handle, CURLOPT_WRITEDATA, (void*) mem_data);
	//curl_easy_setopt(handle, CURLOPT_USERAGENT, MYUSERAGENT);

	CURLcode res = curl_easy_perform(handle);

	if (res != CURLE_OK)
        return 1;

	return 0;
}

std::string* CURLWrapper::getDataPointer()
{
    return &data;
}
