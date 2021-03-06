﻿#include<opencv2\opencv.hpp>
#include<iostream>
#include"Structure_propagation.h"
#include"Texture_Propagation.h"
#include"Photometric_Correction.h"
#include"param.h"
#include<math.h>
using namespace cv;
using namespace std;
void test(){
	string path = "test_data/";
	Mat a = imread(path + "test2.jpg");
	//Mat a = imread(path+"test1_half.jpg");
	//Mat a = imread(path + "test3.bmp");
	Structure_propagation s(a);
	s.getMask();
	s.getCurves();
	s.getAnchors();
	s.drawAnchors();
	//s.testOneCurve();
	s.getNewStructure();
	Texture_Propagation tp(&s);
	//tp.partition();
	//tp.show_partition_image();
	tp.synthesize_texture();
	waitKey();
	destroyAllWindows();
}
void test1() {
	Point2i p1(0, 0);
	Point2i p2(3, 3);
	Point2i p3(4, 0);
	Point2i p4(5, 6);
	Point2i p5(1, 1);
	Point2i p6(4, 2);

	Rect rec1(p1, p2);
	Rect rec2(p3, p4);
	Rect rec3(p5, p6);
	Rect inter = rec1 & rec2;
	Rect i = rec1 & rec3;
	cout << rec1.contains(p2);
	cout << endl;
}
void test2() {
	int x = 1;
	double sigma = 1;
	double pi = 3.14;
	cout << exp(-x * x / (2 * sigma*sigma)) / (sigma*sqrt(2 * pi)) << endl;
	getchar();
	getchar();
}
void test4() {
	double sigma = 0.4;
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> rand(0, sigma);
	for (int i = 0; i < 10; i++) {

		cout << rand(gen) << endl;
	}
	getchar();
	getchar();
}
void test5() {
	vector<vector<int>> a, b;
	vector<int>tmp;
	for (int i = 0; i < 5; i++) {
		tmp.push_back(i);
	}
	a.push_back(tmp);
	tmp.clear();
	for (int j = 6; j < 10; j++) {
		tmp.push_back(j);
	}
	a.push_back(tmp);
	b.assign(a.begin(), a.end());
	a.clear();
	cout << "" << endl;

}
void test6() {
	std::unordered_map<std::string, double>
		myrecipe,
		mypantry = { { "milk",2.0 },{ "flour",1.5 } };

	std::pair<std::string, double> myshopping("baking powder", 0.3);

	myrecipe.insert(myshopping);                        // copy insertion
	myrecipe.insert(std::make_pair<std::string, double>("eggs", 6.0)); // move insertion
	myrecipe.insert(mypantry.begin(), mypantry.end());  // range insertion
	myrecipe.insert( { "salt",0.1 } );    // initializer list insertion
	myrecipe.insert({ "salt",0.2 });    // initializer list insertion
	std::cout << "myrecipe contains:" << std::endl;
	for (auto& x : myrecipe)
		std::cout << x.first << ": " << x.second << std::endl;

	std::cout << std::endl;
	getchar();
	getchar();
}
void test7() {
	Point2i p1(1, 1);
	Point2i p2(1, 1);
	bool e = p1 == p2;
	cout << e << endl;
	cout << endl; 
}
void test9() {
	Mat src, dst, mask;
	dst = imread("test_data/3.jpg");
	src = imread("test_data/src.png");
	mask = imread("test_data/3_mask.png");
	//Mat mask, gray;
	//cvtColor(src, gray, CV_BGR2GRAY);
	//threshold(gray, mask, 150, 255, THRESH_BINARY || THRESH_OTSU);
	//Mat element = getStructuringElement(MORPH_RECT, Size(10, 10), Point(-1, -1));
	//dilate(mask, mask, element);
	imshow("src", src);
	imshow("dst", dst);
	imshow("mask", mask);
	//waitKey(0);
	Mat blend;
	seamlessClone(src, dst, mask, Point(dst.cols/2, dst.rows/2), blend, NORMAL_CLONE);

	imshow("blend", blend);
	waitKey(0);
}
int main() {
	test();
}

