#include <HiddenFrame_Headers.h>
#include <iostream>

using namespace std;

int main(){
    try{
        image* test=new image("../../resources/images/test/input/test_image_1.jpg");
        test->displayImageProperties();
        int n=2;//pixel spacing
        int arrSize=12;
        int arr[12]={3,1,3,0,2,1,2,0,1,1,1,0};
        test->modify_image(n,arr,arrSize);
        test->write_image("../../resources/images/test/output/test_image_1.png");
        image* payloadTest=new image("../../resources/images/test/output/test_image_1.png");
        string payload=payloadTest->retrieve_payload(n);
        cout <<"Hidden Message is " <<payload << endl;
    }
    catch (const std::invalid_argument& e1){
        cerr << "Encountered an exception: " << e1.what() << endl;
    }
    return 0;
}
//sample image filepaths:
//"../../resources/images/test/input/test_image_1.jpg"
//"../../resources/images/test/input/test_image_2.png"
//"../../resources/images/test/input/test_image_3.png"