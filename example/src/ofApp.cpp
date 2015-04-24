#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(150);
    transEN.request("Ciao","it","en");
    transES.request("Ciao","it","es");
    transFR.request("Hello","en","fr");
    transIT.request("Hello","en","it");
    fen.loadFont("frabk.ttf", 16, false);
    fes.loadFont("frabk.ttf", 16, false);
    ffr.loadFont("frabk.ttf", 16, false);
    fit.loadFont("frabk.ttf", 16, false);

    w=ofGetWidth();
    h=ofGetHeight();
    ofAddListener(transEN.requestComplete, this, &ofApp::translateEn);
    ofAddListener(transES.requestComplete, this, &ofApp::translateEs);
    ofAddListener(transFR.requestComplete, this, &ofApp::translateFr);
    ofAddListener(transIT.requestComplete, this, &ofApp::translateIt);
}

void ofApp::translateEn(string & value){
    ofLog()<<value;
    en=value;
    ENc=ofColor(255,45,0);
}

void ofApp::translateEs(string & value){
    ofLog()<<value;
    es=value;
    ESc=ofColor(25,245,10);
}

void ofApp::translateFr(string & value){
    ofLog()<<value;
    fr=value;
    FRc=ofColor(25,2,250);
}

void ofApp::translateIt(string & value){
    ofLog()<<value;
    it=value;
    ITc=ofColor(125,22,120);
}

void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

void ofApp::draw(){
    ofBackgroundGradient(255,0);
    ofSetColor(ENc);
    ofRect(w/2-200,h/2-200,200,200);
    ofSetColor(ESc);
    ofRect(w/2-200,h/2+60,200,200);
    ofSetColor(FRc);
    ofRect(w/2+100,h/2-200,200,200);
    ofSetColor(ITc);
    ofRect(w/2+100,h/2+60,200,200);
    ofSetColor(255);
    fen.drawString(en, w/2-180,h/2-100);
    fes.drawString(es, w/2-180,h/2+160);
    ffr.drawString(fr, w/2+120,h/2-100);
    fit.drawString(it, w/2+120,h/2+160);
}

void ofApp::keyPressed(int key){

}
