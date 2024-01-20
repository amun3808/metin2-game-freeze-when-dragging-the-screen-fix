The game loop freezes when dragging/resizing the window. This is an attempt at fixing that.

We'll open a thread and call "Process()" from there when we receive WM_ENTERSIZEMOVE and then shut it down when receiving WM_EXITSIZEMOVE, continuing our main game loop.

There's also the option of creating a timer when entering WM_ENTERSIZEMOVE, calling "Process()" when receiving WM_TIMER and killing it when receiving WM_EXITSIZEMOVE, but there's quite a big delay till the timer starts and it's also not very reliable, so..

Note: This is HIGHLY experimental, since multithreading PythonApplication might result in data races and crash the client. I tried testing it as good as I could, but note that it's quite a big possibility for that to happen when you least expect it.


Testing it since 22/01/2023


UPDATE: The previous version should be discarded, we're going to handle the move ourselves.
