#include "ofMain.h"
#include "ofAppGlutWindow.h"
#include "ofxTranslated.h"

class xApp : public ofBaseApp {
	public:
		ofEasyCam cam;
		int w,h;
		ofxTranslated trans;

		void setup(){
			ofSetFrameRate(150);

			w=ofGetScreenWidth();
			h=ofGetScreenHeight();
		}

		void update(){
			ofSetWindowTitle(ofToString(ofGetFrameRate()));
		}

		void draw(){
			ofBackgroundGradient(255,0);
		}

		void keyPressed(int key){
			if(key == ' '){
				string res = trans.getResponse("Ciao","it","en");
				ofLog()<<res;
			}
		}
};

int main( ){
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1280, 720, OF_WINDOW);
	ofRunApp(new xApp());

}
