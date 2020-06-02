#include <node.h>
#include <node_buffer.h>
#include <Windows.h>

void setup(const v8::FunctionCallbackInfo<v8::Value>& args){
    v8::Local<v8::Context> context = args.GetIsolate()->GetCurrentContext();
    v8::Local<v8::Object> bufferObj = args[0]->ToObject(context).ToLocalChecked();
    unsigned char *bufferData = (unsigned char *) node::Buffer::Data(bufferObj);
    unsigned long handle = *reinterpret_cast<unsigned long *>(bufferData);
    HWND hwnd = (HWND)handle;
    SetWindowPos(hwnd, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOACTIVATE);
    long style = GetWindowLong(hwnd, GWL_EXSTYLE);
    style |= WS_EX_TOOLWINDOW;
    SetWindowLong(hwnd, GWL_EXSTYLE, style);  
}

void Initialize(v8::Local<v8::Object> exports){
    NODE_SET_METHOD(exports, "setup", setup);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize);