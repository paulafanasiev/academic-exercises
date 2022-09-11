<meta charset="utf-8">
<?php
set_time_limit(0);
function get_string_between($string, $start, $end){
    $string = ' ' . $string;
    $ini = strpos($string, $start);
    if ($ini == 0) return '';
    $ini += strlen($start);
    $len = strpos($string, $end, $ini) - $ini;
    return substr($string, $ini, $len);
}

define('TELEGRAM_TOKEN', '-');


define('TELEGRAM_CHATID', '-');



function message_to_telegram($text)
{
    $ch = curl_init();
    curl_setopt_array(
        $ch,
        array(
            CURLOPT_URL => 'https://api.telegram.org/bot' . TELEGRAM_TOKEN . '/sendMessage',
            CURLOPT_POST => TRUE,
            CURLOPT_RETURNTRANSFER => TRUE,
            CURLOPT_TIMEOUT => 10,
            CURLOPT_POSTFIELDS => array(
                'chat_id' => TELEGRAM_CHATID,
                'text' => $text,
            ),
        )
    );
    curl_exec($ch);
}


function GetData2($url){
		
$ch = curl_init($url);
//curl_setopt($ch, CURLOPT_USERAGENT, "Mozilla/4.0 (compatible;)");
//curl_setopt($ch, CURLOPT_USERAGENT, 'Opera/9.80 (Windows NT 5.1; U; ru) Presto/2.7.62 Version/11.01');
//curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
$ua[0] = 'Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US) AppleWebKit/525.13 (KHTML, like Gecko) Chrome/0.A.B.C Safari/525.13';
$ua[1] = 'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.100 Safari/537.36';
$ua[2] = 'Mozilla/5.0 (Windows NT 6.2; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/29.0.1547.2 Safari/537.36';
curl_setopt($ch, CURLOPT_COOKIEFILE, __DIR__ . '/cookie.txt');
curl_setopt($ch, CURLOPT_COOKIEJAR, __DIR__ . '/cookie.txt');
curl_setopt($ch, CURLOPT_REFERER, 'http://yandex.ru');
curl_setopt($ch, CURLOPT_USERAGENT, $ua[2]);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
curl_setopt($ch, CURLOPT_HEADER, false);
curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1);


curl_setopt($ch, CURLOPT_TIMEOUT, 180);
$content = curl_exec($ch);
sleep (1);
curl_close($ch); 
$explode='<article id="';
$a= explode ( $explode,  $content );
 return $a;
}
echo ' <br/>';

		echo "заказали данные по адресу: https://www.pepper.ru/new";
		echo ' <br/>';
		flush ();
		$a= GetData2("https://www.pepper.ru/new");
		$hostname = "localhost"; 
$username = "-"; 
$password = "-";  
$dbName = "pepper"; 
$tablename = "sent";
$allinfostart='<strong class="thread-title">';
$allinfoend='<span class="thread-divider">';
$namestart="data-t='threadLink'data-t-click";
$nameend="</a></strong>";
$pricestart='<span class="thread-price text--b cept-tp size--all-l size--fromW3-xl">';
$oldpricestart='<span class="mute--text text--lineThrough size--all-l size--fromW3-xl">';
$URLstart='href="https://www.pepper.ru/deals/';
$URLend='"';
$priceend='₽';
$straighturlstart="https://www.pepper.ru/visit/thread/";
$mysqli = new mysqli($hostname, $username, $password, $dbName);
if (mysqli_connect_errno()) {
    echo "Connect failed: %s\n".mysqli_connect_error();
}
echo "Host information: %s\n".$mysqli->host_info;


		for ($i=1; $i<count($a); $i++)
{
	echo $i;
	//echo htmlspecialchars($a[$i]);

$nopricestart='<span class="thread-price text--b cept-tp size--all-l text--color-greyShade">';
$pricetmp=str_replace(' ', '',get_string_between($a[$i],$pricestart,$priceend));
$oldpricetmp=str_replace(' ', '',get_string_between($a[$i],$oldpricestart,$priceend));
//echo "<br/><br/>oldpricetmp=".htmlspecialchars($oldpricetmp)."<br/><br/>";


$noprice=str_replace(' ', '',get_string_between($a[$i],$nopricestart,$priceend));
$URL='https://www.pepper.ru/deals/'.get_string_between($a[$i],$URLstart,$URLend);
$URLstraight=$straighturlstart.get_string_between($a[$i],$straighturlstart,$URLend);
$name=get_string_between($a[$i],$namestart,$nameend);
$skidka=$oldpricetmp-$pricetmp;
$procent= (float)$skidka/$oldpricetmp*100;
echo ' <br/>';
echo $procent."%  ".$skidka.' скидка на '.$name.' за '.$pricetmp.' вместо '.$oldpricetmp.' url= '.htmlspecialchars($URL);
echo ' <br/>';
$result = $mysqli->query("SELECT * FROM `{$tablename}`  WHERE `URL` = '{$URL}'");
$rows = $result->num_rows; // количество полученных строк
$row = $result->fetch_assoc();
var_dump($row);
$tmp=get_string_between($a[$i],$allinfostart,$allinfoend);
//echo $tmp;
if ($rows>0)
echo "ЕСТЬ В БАЗЕ!!!";
else
if($skidka>1000&$procent>65&& ! $noprice&& $pricetmp!=0)
{
	$pricetmp=round(pricetmp);
echo "FOUND!!!!!!";
mail ( 'paulafanasiev@gmail.com', "PEPPER ".date("F j, Y, g:i a"),$procent.'% '.$name.' '.$URL);
message_to_telegram("PEPPER ".$procent.'% '.$name.' '.$URL." \n ".$URLstraight);
$result = $mysqli->query("INSERT INTO `{$tablename}` (`URL`, `NAME`,`SKIDKA`,`PRICE`,`OLDPRICE`) VALUES ('{$URL}', '{$name}', '{$procent}', '0', '0')");
echo $result;
echo "INSERT INTO `{$tablename}` (`URL`, `NAME`,`SKIDKA`,`PRICE`,`OLDPRICE`) VALUES ('{$URL}', '{$name}', '{$procent}', '0', '0')";
}
		echo ' <br/>';
		echo ' <br/>';
}
	
		flush ();

?>
