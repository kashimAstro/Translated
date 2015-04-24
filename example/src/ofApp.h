#include "ofMain.h"
#include "ofxTranslated.h"

class ofApp : public ofBaseApp {
	public:
		ofEasyCam cam;
		int w,h;
		ofxTranslated transEN;
		ofxTranslated transES;
		ofxTranslated transFR;
		ofxTranslated transIT;
		ofTrueTypeFont fen,fes,ffr,fit;
		string en,es,fr,it;
		ofColor ENc,ESc,FRc,ITc;

		void setup();
		void translateEn(string & value);
		void translateEs(string & value);
		void translateFr(string & value);
		void translateIt(string & value);
		void update();
		void draw();
		void keyPressed(int key);
};
