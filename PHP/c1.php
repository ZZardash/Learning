<!doctype html>
<html>
    <head>
        <meta charset="utf-8">
    </head>
    <body>
        <div>
            <?php
                print("-----ECHO vs PRINT----<br>");
                echo print("Test");
                
                print("<br><br>-----FORMAT----<br>");
                $firstName = "Zardash";
                echo "Name is {$firstName}";
                
                print("<br><br>-----CONSTANTS----<br>");
                const STATUS_PAID = 'paid';
                echo STATUS_PAID;
                echo defined("STATUS_PAID");
                echo "<br>";
                $isJump = "JUMP";
                define('STATUS_'. $isJump, 1);
                //echo STATUS_JUMP;

                print("<br><br>-----TYPES----<br>");
                $isComplete = true; //bool
                $score = 45; //int    
                $price = 0.99; //double
                $hello = "Test1"; //string

                echo gettype($isComplete)."<br>";
                echo gettype($score)."<br>";
                echo gettype($price)."<br>";
                echo gettype($hello)."<br>";

                var_dump($isComplete);
                var_dump($score);

                $a = "5";
                $a = (int) $a;//Type casting
                var_dump($a);
                
                print("<br><br>-------------ARRAYS------------<br>");
                $numbers = [1, 2, 3, 0.5, -2.3, "A", "b", true];
                print_r($numbers);
                echo "<br>";
                $langs = array("Python", "C", "JavaScript");

                echo "<pre>";
                print_r($langs);
                echo "</pre>";
                
                echo "<br>".count($langs);
                array_push($langs, "Ruby", "Java", "PHP");
                
                echo "<br>";

                echo "<pre>";
                print_r($langs);
                echo "</pre>";

                echo var_dump(isset($langs));

                $langs[] = "C#"; //Same with array push
                echo "<pre>";
                print_r($langs);
                echo "</pre>";

                //Array Keys
                $langs2 = [
                    "php" => "3.1",
                    "python" => "8.0"
                ];
                echo "<pre>";
                print_r($langs2);
                echo "</pre>";
                
                $langs3 = [
                    0 => "3.1",
                    0.14 => "8.0",
                    0.75 => "9.5"
                ];
                //Overwrites 'til the last element
                echo "<pre>";
                print_r($langs3);
                echo "</pre>";

                array_shift($langs);
                echo "<pre>";
                print_r($langs);
                echo "</pre>";


                print("<br><br>-----FUNCTIONS----<br>");
                //declare(strict_types=1);//If we do this stirng wouldn't be exceptable
                function sum($x, $y){
                    return $x + $y;
                }
                $x = 3;
                $y = 2;
                echo "{$x} + {$y} = ".sum(3, "2"); //Even the value is string php convert integer.
                
                print("<br><br>-----BOOLEANS----<br>");
                //$isComplete = false;
                //$isComplete = [];
                $isComplete = 1;

                //0, -0 -> false
                //0.0, -0.0 -> false
                //" " -> false
                //"0" -> false
                //[] -> false
                //null -> false

                if ($isComplete){
                    echo "Success";
                } else {
                    echo "Fail";
                }

                print("<br><br>-----INTEGERS----<br>");
                echo PHP_INT_MAX."<br>";
                echo PHP_INT_MIN."<br>";
                echo 0x2A;//Decimal

                print("<br><br>-----FLOATS----<br>");
                $x = 13.5e3;//(.10^y)
                echo $x."<br>";
                var_dump($x);

                echo "<br>";
                echo PHP_FLOAT_MAX;
                
                echo "<br>";
                echo floor(7.4);

                echo "<br>";
                echo ceil(4.3);

                echo "<br>";
                echo ceil((0.1+0.2)*10); // (0.1+0.2=0.3000004)!!!

                //PROBLEMS
                echo "<br>";
                $x = 0.23;
                $y = 1 - 0.77;

                if ($x == $y) echo "true";
                else echo "false"; //(1-0.77 = 0.230000x)!!!!

                print("<br><br>-----STRINGS----<br>");
                $firstName = "Will";
                $lastName = "Smith";
                $fullName = "{$firstName} {$lastName}";

                echo $fullName."<br>";
                echo $fullName[0];
                echo $fullName[-1];

                //Heredoc (Variables printed)
                echo "<br>";
                $text = <<<TEXT
                Line1
                Line2 $x
                Line3 $y
                TEXT;

                echo nl2br($text);

                //Nowdoc (Variables couldn't print)
                echo "<br><br>";
                $text = <<<'TEXT'
                Line1
                Line2 $y
                Line3 $x
                TEXT;

                echo nl2br($text);
                
                print("<br><br>-----NULL----<br>");
                $x = 123;
                var_dump($x === NULL);

                print("<br><br>-----OPERATORS----<br>");
                $x = 5;
                $y = "5";
                var_dump($x == $y);
                echo "<br>";
                var_dump($x === $y);//Also checks the data type is equal or not
                echo "<br>";
                var_dump($x !== $y);
                echo "<br>";
                var_dump($x <=> $y);//Return 1, -1 or 0;

                //Ternary Operator
                $x = "Hello World";
                $y = strpos($x, "H");

                $result = $y === false ? "H not found" : "H found at index" . $y;
                echo "<br>";
                echo $result;

                echo "<br>";
                $z = $x ?? "Hello";
                var_dump($z);

                print("<br><br>-----MATCH/SWITCH----<br>");
                $paymentStatus = 1;
                $statusDisplay = match($paymentStatus){
                    1 => "Paid",
                    2 => "Payment Declined",
                    3 => "Payment Declined",
                    default => "Unknown Payment Status",
                };

                echo $statusDisplay;

                print("<br><br>-----FUNCTIONS----<br>");
                function pwr($x, $y){
                    if ($y < 1)
                        return 1;
                    return $x * pwr($x, $y-1); 
                }
                echo pwr(5,20);

                //declare(strict_types = 1);//If we declare this we get error because "1" is not an integer
                function eben(): int{
                    return "1";
                }
                echo "<br>";
                var_dump(eben());
                echo "<br>";
                //VARIADIC FUNCTIONS
                //declare(strict_types=1); //This will avoid the type complexity.

                function sum1(...$numbers){
                    return array_sum($numbers);
                }
                echo sum1(1,3,2,45,2);
                echo "<br>";

                //or

                $arr = [1,2,34,3,4,2];
                echo sum1(1,2,...$arr);//Splat operator
                
                setcookie(name:"dayin", value:"asds", httponly: true);
                
                //VARIABLE ANONYMOUS CALLABLE ARROW FUNCTIONS
                echo "<br>";
                function s1(...$numbers){
                    return array_sum($numbers);
                }
                $x = "s1";
                if (is_callable($x))
                    echo $x(1,2,3,4);
                else 
                    echo "Not Callable";

                print("<br><br>-----GLOBAL & STATIC VARS----<br>");
                $x = 5;
                function eben1(){
                    global $x;
                    echo $GLOBALS["x"];
                }
                eben1();
                echo "<br>";

                function getValue() {
                    static $value = null; //If this global run 3 times
                    if ($value === null) $value = svef();
                    return $value;
                }

                function svef(){
                    sleep(2);
                    echo "Proccessing.";
                    return 10;
                }
                echo getValue();//value is null
                echo getValue();//value is not null anymore
                echo getValue();

                print("<br><br>-----ERROR REPORTING----<br>");
                var_dump(error_reporting(0));
                //streqr("eben");

                print("<br><br>-----TIME AND DATE----<br>");
                echo date("Y/M/D");

                print("<br><br>-----SESSIONS----<br>");
                //(INFO):
                //SESSION -> Stored on SERVER side    
                //COOKIE -> Stored on CLIENT side (browsers)    
                //Session must start after any output 
                $_SESSION["name"] = "Sertaç Bera Yurtaslan";
                session_start(); //This will start the session
                var_dump($_SESSION);
                //unset($_SESSION["name"]);
                //session_destroy();

                print("<br><br>-----COOKIES----<br>");
                setcookie(//
                    "userName",//Cookie Name
                    "Gio", //Cookie Value
                    time() - 10, //Cookie expire time
                    "/Final/final3.php", //Cookie Directory
                    " ", //Cookie Domain
                    false, //Secure connection check
                    false //Only http check
                );

               
            ?>
        </div>
    </body>
    <style>
        div{
            color:aquamarine
        }

        body{
            background-color: black;
        }
    </style>
</html>
