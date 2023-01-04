<!DOCTYPE html>
<html lang="en">
<style>
    .score_submit {
        background-color: #1961aa;
        color:white;
        padding: 8px 20px;
        border: 1px solid #0c335a;
        transition: all 0.3s ease-out;
        border-radius: 10px;
        margin-bottom: 15px;
        padding: 8px 10px;
        font-size: 20px;
        font-family: Arial, sans-serif;
        width: 400px;
        height: 60px;
        margin-left: 100px;
        margin-top: 50px;
        margin-bottom: 50px;
    }

    .score_submit:hover {
        background-color: white;
        color:#0c335a;
        border: 1px solid #1961aa;
    }

    .score_display {
        background-color: #ffffff;
        box-shadow: 0 4px 8px 0 rgba(0,0,0,0.2);
        height: 600px;
        width: 600px;
        margin-top : 50px;
        text-align: center;
        display: flex;
        justify-content: center;
        align-items: center;
    }

    .score_display h5{
        font-size:50px;
        justify-content: center;
        align-items: center;
    }
</style>

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" type="text/css" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css">
    <link rel="stylesheet" href="./assets/css/index.css">
    <title>Score</title>
<?php
    // Start the session
	session_start();
    $socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
    if ($socket === false) {
        echo "socket_create() failed: reason: " . socket_strerror(socket_last_error()) . "\n";
    }
    // connect to server
    $result = socket_connect($socket, "127.0.0.1", 9999);
    if ($result === false) {
        echo "socket_connect() failed.\nReason: ($result) " . socket_strerror(socket_last_error($socket)) . "\n";
    }
    if (isset($_POST['stop'])){
         $msg = "8|".$_SESSION["username"]."|".$_SESSION["position"]."|";
        //echo $response;
  
    }else {

    $msg = "9|".$_SESSION["username"]."|".$_SESSION["position"]."|";
    }

    $ret = socket_write($socket, $msg, strlen($msg));
    if (!$ret) die("client write fail:" . socket_strerror(socket_last_error()) . "\n");

        // receive response from server
    $response = socket_read($socket, 1024);
    if (!$response) die("client read fail:" . socket_strerror(socket_last_error()) . "\n");

    $response = explode("|", $response);

    if ($response[0] == "15" ) {
    	$_SESSION["score"] = $response[1];
        
    }else {
        echo "<script>alert('Fail!');</script>"; 
    }
    socket_close($socket);
?>
</header>
<body>
    <?php include('home_navbar.php'); ?>
    <div class="home_container">
<div class=" d-flex justify-content-center"> 
    <div class="score_contain  list-group">
<div class="score_display">
        <h5>YOUR SCORE: <?php echo $_SESSION["score"];?> </h5>
</div>
 <div class="score_button">
<form action="home.php" method="post">
        <input type="submit" class="score_submit" name ="home" value="OK" >
    </form>
</div>
</div>
</div>
    <?php include('footer.php'); ?>
</body>

</html>