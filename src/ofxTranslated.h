#include "ofMain.h"
#include "ofxJSON.h"
#include "ofThread.h"

//http://mymemory.translated.net/api/get?q=Hello World!&langpair=en|it
//http://mymemory.translated.net/doc/spec.php

class ofxTranslated : public ofThread {
	public:
                string cmd,da,a;
	        ofxJSONElement result;

		ofxTranslated(){ }
		~ofxTranslated(){ }

                ofEvent<string> requestComplete;

		void request( string command, string _da, string _a ){
                        cmd = command;
			da  = _da;
			a   = _a;
                        startThread( );
                }

		void stop(){
                        stopThread( );
		}

		string getResponse(string translate, string _da, string _a){
	                string url;
	                string response;
	                url="http://mymemory.translated.net/api/get?q="+translate+"&langpair="+_da+"|"+_a;
	                ofHttpResponse resp = ofLoadURL(url);
	                bool parsingSuccessful = result.parse(resp.data);
	                if (parsingSuccessful) {
			    string p = result["matches"][0]["translation"].asString();

	                    response=p; 
	                }
	                else{
	                    response="Failed JSON!";
	                }
	                return response;
			stopThread();
		}

		void threadedFunction(){
                        string result = getResponse(cmd.c_str(),da.c_str(),a.c_str());
                        ofNotifyEvent( requestComplete, result, this );
                }

};
