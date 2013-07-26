#include <node.h>
#include <v8.h>

#include <string>
#include <iostream>
#include <libnotify/notify.h>

using namespace v8;

Handle<Value> Libnotify(const Arguments& args) {
    HandleScope scope;


    /*
     * Ensure minimum requirements are met
     */
    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(
            String::New("Wrong number of arguments")
        ));

        return scope.Close(Undefined());
    }


    /*
     * Define defaults
     */
    Local<Value> title       = String::New("Node-Notify");
    Local<Value> message     = args[0];
    Local<Value> dialog_icon = String::New("dialog-information");


    /*
     * Find optional parameters
     */
    if(args.Length() > 1 && args[1]->IsObject()) {
        Local<Object> options = args[1]->ToObject();

        if(options->Has(String::New("title"))) {
            title = options->Get(String::New("title"));
        }
        if(options->Has(String::New("dialogIcon"))) {
            dialog_icon = options->Get(String::New("dialogIcon"));
        }
    }


    /*
     * Initialize notification and send
     */
    notify_init(*String::AsciiValue(title));
    NotifyNotification * Hello = notify_notification_new (
        *String::AsciiValue(title),
        *String::AsciiValue(message),
        *String::AsciiValue(dialog_icon)
    );
    notify_notification_show (Hello, NULL);


    /*
     * Return undefined
     */
    return scope.Close(Undefined());
}

void init(Handle<Object> exports) {
    exports->Set(String::NewSymbol("notify"),
            FunctionTemplate::New(Libnotify)->GetFunction());
}

NODE_MODULE(notify, init)
