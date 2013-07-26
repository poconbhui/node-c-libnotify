c-libnotify
===========

This is a spacese wrapper around the C libnotify library.

Example Usage:

    var notify = require("c-libnotify").notify;

    notify("Hello!", {title:"MyApp", dialogIcon="/path/to/icon"});
