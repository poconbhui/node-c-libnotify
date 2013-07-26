{
    "targets": [
        {
            "target_name": "c-libnotify",
            "sources": [ "src/notify.cc" ],
            "libraries": [
                "<!@(pkg-config --libs libnotify)"
            ],
            "include_dirs": [
                "<!@(pkg-config --cflags-only-I libnotify | sed 's/-I//g')"
            ]
        }
    ]
}
