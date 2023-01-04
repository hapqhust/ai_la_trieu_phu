<?php
    session_start();
    if (isset($_POST['logout'])) {

            // create socket
            $socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
            if ($socket === false) {
                echo "socket_create() failed: reason: " . socket_strerror(socket_last_error()) . "\n";
            }
            // connect to server
            $result = socket_connect($socket, "127.0.0.1", 9999);
            if ($result === false) {
                echo "socket_connect() failed.\nReason: ($result) " . socket_strerror(socket_last_error($socket)) . "\n";
            }

            // 
            $msg = "2|" . $_SESSION["username"] . "|";

            $ret = socket_write($socket, $msg, strlen($msg));
            if (!$ret) die("client write fail:" . socket_strerror(socket_last_error()) . "\n");

            // receive response from server
            $response = socket_read($socket, 1024);
            if (!$response) die("client read fail:" . socket_strerror(socket_last_error()) . "\n");
            echo $response;

            // split response from server
            $response = explode("|", $response);
            if ($response[0] == "8") {
                session_destroy();
                echo "<script>alert('Are you sure logout ?');</script>";
                echo "<script>window.location.href = 'index.php';</script>";
                
            } else {
                echo "<script>alert('fail!');</script>";
                echo "<script>window.location.href = 'home.php';</script>";
            }

            // close socket
            socket_close($socket);
        }

    ?>