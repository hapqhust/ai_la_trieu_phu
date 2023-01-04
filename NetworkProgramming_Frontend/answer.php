<?php
session_start();
if (isset($_POST['answer'])) {

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
    
    $answer = $_POST['answer'];
    $answer = explode(".", $answer)[0];
    $msg = "6|".$_SESSION["question_id"]."|".$answer."|";

    $ret = socket_write($socket, $msg, strlen($msg));
    if (!$ret) die("client write fail:" . socket_strerror(socket_last_error()) . "\n");

    // receive response from server
    $response = socket_read($socket, 1024);
    if (!$response) die("client read fail:" . socket_strerror(socket_last_error()) . "\n");
    //echo $response;

    // split response from server
    $response = explode("|", $response);

    if ($response[0] == "13" ) {
    	$_SESSION["position"] = $_SESSION["position"] + 1;
        echo "<script>alert('$response[1]');</script>";
        echo "<script>window.location.href = 'playgame.php';</script>";
        
        
        
    }elseif ($response[0] == "19" )  {
        if ($_SESSION["position"]==0){
            $_SESSION["position"]=0;
        }
        elseif ($_SESSION["position"] >=1 && $_SESSION["position"] < 5 )
        {
            $_SESSION["position"]=1;
            
        }elseif($_SESSION["position"]>=5 && $_SESSION["position"] <10 )
        {
            $_SESSION["position"]=5;
        }elseif($_SESSION["position"]>=10 && $_SESSION["position"] <15) {
            $_SESSION["position"] =10;
            
        }
        $msg = "9|".$_SESSION["username"]."|".$_SESSION["position"]."|";

        $ret = socket_write($socket, $msg, strlen($msg));
        if (!$ret) die("client write fail:" . socket_strerror(socket_last_error()) . "\n");

        // receive response from server
        $response = socket_read($socket, 1024);
        if (!$response) die("client read fail:" . socket_strerror(socket_last_error()) . "\n");

        echo "<script>alert('Your answer is incorrect!');</script>";
        echo "<script>window.location.href = 'score.php';</script>";
        
    }

    // close socket
    socket_close($socket);
}
?>