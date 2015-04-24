#include "ofMain.h"
#include "ofAppGlutWindow.h"
#include "ofxTranslated.h"

class xApp : public ofBaseApp {
	public:
		ofEasyCam cam;
		int w,h;
		ofxTranslated transEN;
		ofxTranslated transES;
		ofxTranslated transFR;
		string en,es,fr,rs;

		void setup(){
			ofSetFrameRate(150);
			transEN.request("Ciao","it","en");
			transES.request("Ciao","it","es");
			transFR.request("Hello","en","fr");

			w=ofGetScreenWidth();
			h=ofGetScreenHeight();
                        ofAddListener(transEN.requestComplete, this, &xApp::translateEn);
                        ofAddListener(transES.requestComplete, this, &xApp::translateEs);
                        ofAddListener(transFR.requestComplete, this, &xApp::translateFr);
		}

		void translateEn(string & value){
			ofLog()<<value;
			en=value;
                }

		void translateEs(string & value){
			ofLog()<<value;
			es=value;
                }

		void translateFr(string & value){
			ofLog()<<value;
			fr=value;
                }

		void update(){
			ofSetWindowTitle(ofToString(ofGetFrameRate()));
		}

		void draw(){
			ofBackgroundGradient(255,0);
			ofDrawBitmapStringHighlight(en,ofPoint(10,20,0));
			ofDrawBitmapStringHighlight(es,ofPoint(10,60,0));
			ofDrawBitmapStringHighlight(fr,ofPoint(10,100,0));
		}

		void keyPressed(int key){

		}
};

int main( ){
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1280, 720, OF_WINDOW);
	ofRunApp(new xApp());

}
