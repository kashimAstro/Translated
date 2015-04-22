#include "ofMain.h"
#include "ofxJSON.h"

//http://mymemory.translated.net/api/get?q=Hello World!&langpair=en|it
//http://mymemory.translated.net/doc/spec.php

class ofxTranslated{
	public:
		string langpair;
		string context;
        ofxJSONElement result;

		ofxTranslated(){ }
		~ofxTranslated(){ }

		string getResponse(string translate, string da, string a){
                string url;
                string response;
                url="http://mymemory.translated.net/api/get?q="+translate+"!&langpair="+da+"|"+a;
                ofHttpResponse resp = ofLoadURL(url);
                cout << resp.data << endl;
                bool parsingSuccessful = result.parse(resp.data);
                if (parsingSuccessful) {
                    response=result["OK"]["matches"]["translation"].asString();
                }
                else{
                    ofLog(OF_LOG_ERROR)  << "Failed to parse JSON" << endl;
                }
                return response;
		}

};
