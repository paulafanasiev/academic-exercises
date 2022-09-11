<meta charset="utf-8">

<?php 
// сюда нужно вписать токен вашего бота
define('TELEGRAM_TOKEN', '-');

// сюда нужно вписать ваш внутренний айдишник
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
$hostname = "-"; 
$username = "-"; 
$password = "-"; 
$dbName = "-"; 
$tablename = "goods";
set_time_limit ( 21600 );
$allinfostart='.trigger("product_click",';
$allinfoend=");'>";
$namestart='"productName": "';
$nameendplusstartofurl='", "';
$ENDOFURLPRODUCT='" role="button" target="_blank" tab-index="0" data-html data-toggle="popover" data-placement="left" data-trigger="hover" data-content-target="';
$startofval='productPriceLocal":';
$endofval='",';
$startofwhere='<li><p><b>Магазин:</b><br />';
$endofwhere='</p><p><b>Адрес:</b><br />';
$startoldprice='<div class="markdown-price-old">';
$endoldprice='<i class="rub-icon">';
$URLzero="https://www.goods.ru/product-list?Nf=Price%7CBTWN+0.0+300000.0&No=";
$URLend="&Nr=AND%28product.searchable%3A1%2CNOT%28product.nonSearchable%3A1%29%2Cproduct.siteId%3ASite_6%29&Nrpp=12&Ns=product.weight%7C1%7C%7CPrice%7C0%7C%7Cproduct.rating%7C1%7C%7Cproduct.reviewCount%7C1%7C%7Cproduct.reviewLastDate%7C1%7C%7Cproduct.displayName%7C0&_=1581489412757&cityId=CityCZ_1638";
$numoftov='class="count-products"';
$endnumoftov="</span>";
$mysqli = new mysqli($hostname, $username, $password, $dbName);
if (mysqli_connect_errno()) {
    echo "Connect failed: %s\n".mysqli_connect_error();
}
echo "Host information: %s\n".$mysqli->host_info;

$test1="test";
$test2=1000;
//$result = $mysqli->query( 'SELECT Name, Area FROM Country ORDER BY Area DESC LIMIT 5') or die(mysql_error());
echo "New Start";
flush ();
function cmp($a, $b)
{
    if($a->{'skidka'}==0&&$b->{'skidka'}==0){
		return ($a->{'skidka'} < $b->{'skidka'}) ? -1 : 1;
	}
	if ($a->{'skidka'} == $b->{'skidka'}) {
        return 0;
    }
	return ($a->{'skidka'} > $b->{'skidka'}) ? -1 : 1;
}
function swap(&$x,&$y) {
    $tmp=$x;
    $x=$y;
    $y=$tmp;
}


function get_string_between($string, $start, $end){
    $string = ' ' . $string;
    $ini = strpos($string, $start);
    if ($ini == 0) return '';
    $ini += strlen($start);
    $len = strpos($string, $end, $ini) - $ini;
    return substr($string, $ini, $len);
}



function GetData2($url){
		$explode='<meta itemprop="position" content=';
$ch = curl_init($url);
//curl_setopt($ch, CURLOPT_USERAGENT, "Mozilla/4.0 (compatible;)");
//curl_setopt($ch, CURLOPT_USERAGENT, 'Opera/9.80 (Windows NT 5.1; U; ru) Presto/2.7.62 Version/11.01');
//curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);

curl_setopt($ch, CURLOPT_COOKIEFILE, __DIR__ . '/cookie.txt');
curl_setopt($ch, CURLOPT_COOKIEJAR, __DIR__ . '/cookie.txt');
curl_setopt($ch, CURLOPT_REFERER, 'http://yandex.ru');
curl_setopt($ch, CURLOPT_USERAGENT, 'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.100 Safari/537.36');
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
curl_setopt($ch, CURLOPT_HEADER, false);
curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1);


curl_setopt($ch, CURLOPT_TIMEOUT, 180);
$content = curl_exec($ch);
sleep (1);
curl_close($ch); 

$a= explode ( $explode,  htmlspecialchars_decode($content) );
//echo $a[1];
 return $a;
}
$estskidki=false;
$bmax=1;
$b=1;
//$all[$b]->{'productPriceLocal'}=10;
mail ( 'paulafanasiev@gmail.com', date("F j, Y, g:i a").' sbermegamarket начата проверка!', date("F j, Y, g:i a").' sbermegamarket начата проверка!');
$URLstart = array("https://sbermegamarket.ru/catalog/monitory/page-",
"https://sbermegamarket.ru/catalog/smart-tv-proigryvateli/page-",
"https://sbermegamarket.ru/catalog/televizory/page-",
"https://sbermegamarket.ru/catalog/smartfony/page-",
"https://sbermegamarket.ru/catalog/igrovye-aksessuary-dlya-kompyuterov/page-",
"https://sbermegamarket.ru/catalog/monobloki/page-",
"https://sbermegamarket.ru/catalog/nakopiteli-informacii/page-",
"https://sbermegamarket.ru/catalog/processory/page-",
"https://sbermegamarket.ru/catalog/materinskie-platy/page-",
"https://sbermegamarket.ru/catalog/videokarty/page-",
"https://sbermegamarket.ru/catalog/bloki-pitaniya-dlya-kompyutera/page-",
"https://sbermegamarket.ru/catalog/operativnaya-pamyat/page-",
"https://sbermegamarket.ru/catalog/korpusa-dlya-kompyutera/page-",
"https://sbermegamarket.ru/catalog/ssd-diski/page-",
"https://sbermegamarket.ru/catalog/zhestkie-diski/page-",
"https://sbermegamarket.ru/catalog/sistemy-ohlazhdeniya/page-",
"https://sbermegamarket.ru/catalog/aksessuary-dlya-nakopiteley/page-",
"https://sbermegamarket.ru/catalog/dvd-privody/page-",
"https://sbermegamarket.ru/catalog/servernoe-oborudovanie/page-",
"https://sbermegamarket.ru/catalog/zvukovye-karty/page-",
"https://sbermegamarket.ru/catalog/hdd-i-ssd/page-",
"https://sbermegamarket.ru/catalog/kofemashiny/page-",
"https://sbermegamarket.ru/catalog/igrovaya-operativnaya-pamyat/page-",
"https://sbermegamarket.ru/catalog/igrovye-bloki-pitaniya/page-",
"https://sbermegamarket.ru/catalog/igrovye-processory/page-",
"https://sbermegamarket.ru/catalog/igrovye-videokarty/page-",
"https://sbermegamarket.ru/catalog/setevye-karty/page-",
"https://sbermegamarket.ru/catalog/igrovye-pristavki-playstation/page-",
"https://sbermegamarket.ru/catalog/igrovye-pristavki-xbox/page-",
"https://sbermegamarket.ru/catalog/igrovye-pristavki-nintendo/page-",
"https://sbermegamarket.ru/catalog/aksessuary-dlya-igrovyh-pristavok/page-",
"https://sbermegamarket.ru/catalog/umnye-chasy/page-",
"https://sbermegamarket.ru/catalog/fitnes-braslety/page-",
"https://sbermegamarket.ru/catalog/napolnye-kolonki/page-",
"https://sbermegamarket.ru/catalog/polochnye-kolonki/page-",
"https://sbermegamarket.ru/catalog/sabvufery/page-",
"https://sbermegamarket.ru/catalog/vstraivaemye-kolonki/page-",
"https://sbermegamarket.ru/catalog/av-resivery/page-",
"https://sbermegamarket.ru/catalog/nabory-i-komplekty-akustiki/page-",
"https://sbermegamarket.ru/catalog/usiliteli-hi-fi/page-",
"https://sbermegamarket.ru/catalog/prochaya-hi-fi-tehnika-i-aksessuary/page-",
"https://sbermegamarket.ru/catalog/portativnaya-akustika/page-",
"https://sbermegamarket.ru/catalog/proektory-i-aksessuary/page-",
"https://sbermegamarket.ru/catalog/domashnie-kinoteatry/page-",
"https://sbermegamarket.ru/catalog/mfu/page-",
"https://sbermegamarket.ru/catalog/printery/page-",
"https://sbermegamarket.ru/catalog/planshety/page-",
"https://sbermegamarket.ru/catalog/fotoapparaty/page-",
"https://sbermegamarket.ru/catalog/ekshn-kamery-i-aksessuary/page-",
"https://sbermegamarket.ru/catalog/sumki-i-ryukzaki-dlya-fototehniki/page-",
"https://sbermegamarket.ru/catalog/cifrovye-fotoramki/page-",
"https://sbermegamarket.ru/catalog/radioupravlyaemye-ustrojstva/page-",
"https://sbermegamarket.ru/catalog/shtativy-i-monopody/page-",
"https://sbermegamarket.ru/catalog/elektronnye-knigi-i-aksessuary/page-",
"https://sbermegamarket.ru/catalog/powerline-adaptery/page-",
"https://sbermegamarket.ru/catalog/wi-fi-routery/page-",
"https://sbermegamarket.ru/catalog/kommutatory/page-",
"https://sbermegamarket.ru/catalog/marshrutizatory/page-",
"https://sbermegamarket.ru/catalog/retranslyatory-wi-fi-signala/page-",
"https://sbermegamarket.ru/catalog/setevye-hranilisha/page-",
"https://sbermegamarket.ru/catalog/tochki-dostupa-wi-fi/page-",
"https://sbermegamarket.ru/catalog/usiliteli-internet-signala/page-",
"https://sbermegamarket.ru/catalog/ip-kamery/page-",
"https://sbermegamarket.ru/catalog/sportivnye-naushniki/page-",
"https://sbermegamarket.ru/catalog/naushniki-vkladyshi/page-",
"https://sbermegamarket.ru/catalog/nakladnye-naushniki/page-",
"https://sbermegamarket.ru/catalog/besprovodnye-naushniki/page-",
"https://sbermegamarket.ru/catalog/naushniki-polnorazmernye/page-",
"https://sbermegamarket.ru/catalog/garnitury-dlya-telefonov/page-",
"https://sbermegamarket.ru/catalog/igrovye-naushniki/page-",
"https://sbermegamarket.ru/catalog/morozilniki/page-",
"https://sbermegamarket.ru/catalog/ledogenerator/page-",
"https://sbermegamarket.ru/catalog/mikrovolnovye-pechi/page-",
"https://sbermegamarket.ru/catalog/posudomoechnye-mashiny/page-",
"https://sbermegamarket.ru/catalog/elektricheskie-plity/page-",
"https://sbermegamarket.ru/catalog/gazovye-plity/page-",
"https://sbermegamarket.ru/catalog/kombinirovannye-plity/page-",
"https://sbermegamarket.ru/catalog/nastolnye-plity/page-",
"https://sbermegamarket.ru/catalog/elektrogrili/page-",
"https://sbermegamarket.ru/catalog/myasorubki/page-",
"https://sbermegamarket.ru/catalog/kuhonnye-kombajny-i-mashiny/page-",
"https://sbermegamarket.ru/catalog/tostery/page-",
"https://sbermegamarket.ru/catalog/multipekar/page-",
"https://sbermegamarket.ru/catalog/parovye-konvekcionnye-pechi/page-",
"https://sbermegamarket.ru/catalog/multirezki/page-",
"https://sbermegamarket.ru/catalog/su-vid/page-",
"https://sbermegamarket.ru/catalog/vesy-kuhonnye/page-",
"https://sbermegamarket.ru/catalog/aksessuary-dlya-melkoj-kuhonnoj-tehniki/page-",
"https://sbermegamarket.ru/catalog/drugaya-melkaya-tehnika-dlya-kuhni/page-",
"https://sbermegamarket.ru/catalog/stiralnye-mashiny/page-",
"https://sbermegamarket.ru/catalog/sushilnye-mashiny/page-",
"https://sbermegamarket.ru/catalog/pylesosy/page-",
"https://sbermegamarket.ru/catalog/otparivateli/page-",
"https://sbermegamarket.ru/catalog/parogeneratory/page-",
"https://sbermegamarket.ru/catalog/overloki/page-",
"https://sbermegamarket.ru/catalog/paroochistiteli-i-stekloochistiteli-dlya-okon/page-",
"https://sbermegamarket.ru/catalog/vstraivaemye-duhovye-shkafy/page-",
"https://sbermegamarket.ru/catalog/vstraivaemye-posudomoechnye-mashiny/page-",
"https://sbermegamarket.ru/catalog/vstraivaemye-varochnye-paneli/page-",
"https://sbermegamarket.ru/catalog/vstraivaemye-holodilniki/page-",
"https://sbermegamarket.ru/catalog/vstraivaemye-morozilniki/page-",
"https://sbermegamarket.ru/catalog/vstraivaemye-stiralnye-mashiny/page-",
"https://sbermegamarket.ru/catalog/vstraivaemye-mikrovolnovye-pechi/page-",
"https://sbermegamarket.ru/catalog/drugaya-vstraivaemaya-tehnika/page-",
"https://sbermegamarket.ru/catalog/kondicionery-i-split-sistemy/page-",
"https://sbermegamarket.ru/catalog/ochistiteli-i-uvlazhniteli-vozduha/page-",
"https://sbermegamarket.ru/catalog/elektrobritvy/page-",
"https://sbermegamarket.ru/catalog/elektricheskie-zubnye-shetki-i-irrigatory/page-",
"https://sbermegamarket.ru/catalog/mashinki-dlya-strizhki-volos/page-",
"https://sbermegamarket.ru/catalog/kuhonnaya-naveska/page-",
"https://sbermegamarket.ru/catalog/nabory-posudy-8010105/page-",
"https://sbermegamarket.ru/catalog/skovorody-i-soteyniki/page-",
"https://sbermegamarket.ru/catalog/kastryuli/page-",
"https://sbermegamarket.ru/catalog/kryshki-dlya-posudy/page-",
"https://sbermegamarket.ru/catalog/zharovni/page-",
"https://sbermegamarket.ru/catalog/fondyu/page-",
"https://sbermegamarket.ru/catalog/marmity/page-",
"https://sbermegamarket.ru/catalog/prochaya-posuda-dlya-prigotovleniya/page-",
"https://sbermegamarket.ru/catalog/podstavki-dlya-posudy/page-",
"https://sbermegamarket.ru/catalog/kuhonnye-rejlingi/page-",
"https://sbermegamarket.ru/catalog/prochie-tovary-dlya-hraneniya-produktov/page-",
"https://sbermegamarket.ru/catalog/pishevye-kontejnery/page-",
"https://sbermegamarket.ru/catalog/sushilki-dlya-posudy/page-",
"https://sbermegamarket.ru/catalog/stolovye-servizy/page-",
"https://sbermegamarket.ru/catalog/aksessuary-dlya-servirovki-stola/page-",
"https://sbermegamarket.ru/catalog/stolovye-pribory/page-",
"https://sbermegamarket.ru/catalog/lyustry/page-",
"https://sbermegamarket.ru/catalog/torshery/page-",
"https://sbermegamarket.ru/catalog/fonariki/page-",
"https://sbermegamarket.ru/catalog/nastolnye-lampy/page-",
"https://sbermegamarket.ru/catalog/stremyanki/page-",
"https://sbermegamarket.ru/catalog/shvabry-i-aksessuary/page-",
"https://sbermegamarket.ru/catalog/veniki-shetki-sovki/page-",
"https://sbermegamarket.ru/catalog/poryadok-v-dome/page-",
"https://sbermegamarket.ru/catalog/tovary-dlya-hraneniya-veshey/page-",
"https://sbermegamarket.ru/catalog/aksessuary-dlya-vannoj/page-",
"https://sbermegamarket.ru/catalog/polki-i-etazherki-dlya-vannoj/page-",
"https://sbermegamarket.ru/catalog/mebel-dlya-letnego-otdyha/page-",
"https://sbermegamarket.ru/catalog/tovary-dlya-piknika/page-",
"https://sbermegamarket.ru/catalog/postelnoe-bele/page-",
"https://sbermegamarket.ru/catalog/odeyala-i-podushki/page-",
"https://sbermegamarket.ru/catalog/tekstil-dlya-vannoj/page-",
"https://sbermegamarket.ru/catalog/shtory-zhalyuzi-karnizy/page-",
"https://sbermegamarket.ru/catalog/pledy-i-pokryvala/page-",
"https://sbermegamarket.ru/catalog/namatrasniki-i-chehly/page-",
"https://sbermegamarket.ru/catalog/noutbuki/page-",
"https://sbermegamarket.ru/catalog/sistemnye-bloki/page-",
"https://sbermegamarket.ru/catalog/kabeli-i-perehodniki/page-",
"https://sbermegamarket.ru/catalog/kronshtejny-i-stojki-dlya-televizorov/page-",
"https://sbermegamarket.ru/catalog/holodilniki/page-",
"https://sbermegamarket.ru/catalog/vytyazhki/page-",
"https://sbermegamarket.ru/catalog/naushniki/page-",
"https://sbermegamarket.ru/catalog/kosmeticheskie-pribory/page-",
"https://sbermegamarket.ru/catalog/aksessuary-dlya-planshetov/page-",
"https://sbermegamarket.ru/catalog/aksessuary-dlya-telefonov/page-");
foreach ($URLstart as $URLstartotest)
{
	$bmax=1;
	$num=0;
	$noprice=0;
for($b=1;$b<=$bmax and $b<800 and $noprice<25;$b++)
{
$tmpurl=$URLstartotest.$b;
echo ' <br/> ';
echo $tmpurl;
echo ' <br/> ';
$a= GetData2($tmpurl);
$try=0;
while(strlen(htmlspecialchars_decode($a[4]))<20 and $try<5)
{
	echo htmlspecialchars_decode($a[1]);
	echo ' <br/> reload ';
	echo ' strlen=';
echo strlen(htmlspecialchars_decode($a[1]));
echo '<br/>';
flush ();
$a= GetData2($tmpurl);
sleep (1);
$try++;
}
sleep (1);
echo ' <br/> b=';
echo $b;
if($bmax<5)
{
	echo 'UPDATE BMAX';
	$tmp2=get_string_between($a[count($a)-1],'listing__show-more','<li class="next">');
	$tmp=explode ( '/page-',  $tmp2);
	
	
	//$bmax=get_string_between($tmp[count($tmp)-1],'"pageCount":',',"perPage');
	$tmp3=explode ( '/',  $tmp[count($tmp)-1]);
	echo '<br>'.'tmp='.$tmp3[0].'<br>';
	$bmax=$tmp3[0];
	echo '<br>'.'bmax='.$bmax.'<br>';
	echo htmlspecialchars($tmp2);
}
$mailform = "Скидка>70%(или > 50% при цене выше 10к)\n";
echo 'count a = '.count($a).'<br>';
$noprice=0;

for ($i=5; $i<count($a); $i++)
{
//echo htmlspecialchars($a[$i]);
$tmp=get_string_between($a[$i],$allinfostart,$allinfoend);
//echo $tmp;
//$url=get_string_between(htmlspecialchars_decode($a[$i]),'<a href="','" class="');
$all[$num]=json_decode(htmlspecialchars_decode($tmp));
echo $i.'=';
var_dump($all[$num]);
$all[$num]->{'item'}->{'price'}=intval(substr(str_replace(' ', '',get_string_between(htmlspecialchars_decode($a[$i]),'<div class="item-price-from"><span>',"</span>")),4,-5));

$all[$num]->{'item'}->{'name'}=get_string_between(htmlspecialchars_decode($a[$i]),'" title="','"');
$all[$num]->{'url'}=get_string_between(htmlspecialchars_decode($a[$i]),'<a href="','"');
$all[$num]->{'item'}->{'bonus_rub'}=0;
if($all[$num]->{'item'}->{'price'}==0)
	$all[$num]->{'item'}->{'price'}=intval(substr(str_replace(' ', '',get_string_between(htmlspecialchars_decode($a[$i]),'content="RUB"><span>',"</span>")),0,-3));
flush ();
echo 'url='.$all[$num]->{'url'}.'<br>';
echo 'name='.$all[$num]->{'item'}->{'name'}.'<br>';
echo 'price='.$all[$num]->{'item'}->{'price'}.'<br>';
echo 'bonus='.$all[$num]->{'item'}->{'bonus_rub'}.'<br>';
$result = $mysqli->query("SELECT * FROM `{$tablename}` WHERE `URL` LIKE '{$all[$num]->{'url'}}'");
$row = $result->fetch_assoc();
if(strlen($all[$num]->{'url'})>25)
if ($row['productPriceLocal']>0 and $all[$num]->{'item'}->{'price'}>0) {
	echo 'цена в базе=';
	echo $row['productPriceLocal'];
	$all[$num]->{'NALICHIE'}=TRUE;

	$all[$num]->{'skidka'}=($row['productPriceLocal']-$all[$num]->{'item'}->{'price'})*100.0/$row['productPriceLocal'];
	echo 'skidka= '.$all[$num]->{'skidka'}.'%';

if($all[$num]->{'item'}->{'bonus_rub'}>0.7*$all[$num]->{'item'}->{'price'} and $row['bonus']+500<$all[$num]->{'item'}->{'bonus_rub'} and ($row['SENT']<3))
	{
		echo ' <br/>';
echo ' !!!!ВЕРОЯТНО ОШИБКА БОНУСОВ!!!!:';
$mailform =$mailform.'<a href="'.'https://www.sbermegamarket.ru'.$all[$num]->{'url'}.'">'.$all[$num]->{'item'}->{'name'}.' за '.$all[$num]->{'item'}->{'price'}.' bonus = '.$all[$num]->{'item'}->{'bonus_rub'}.' ранее бонусов '.$row['bonus'].'</a>\n'; 
$TMP2=$row['SENT']+1; 
		$mysqli->query("UPDATE `{$tablename}` SET `SENT` = '{$TMP2}' WHERE `URL` LIKE '{$all[$num]->{'url'}}'");
	}
if($row['productPriceLocal'] !=$all[$num]->{'item'}->{'price'}){
$estskidki=true;
if(($row['SENT']<3)and($all[$num]->{'NALICHIE'}==TRUE) and ($all[$num]->{'skidka'}>70 or ($row['productPriceLocal']>10000 and $all[$num]->{'skidka'}>50 and $URLstartotest != "https://sbermegamarket.ru/catalog/lyustry/page-")or((stripos($all[$num]->{'item'}->{'name'},'apple')!=false)and ($all[$num]->{'skidka'}>50) and $URLstartotest !="https://sbermegamarket.ru/catalog/aksessuary-dlya-planshetov/page-" and $URLstartotest !="https://sbermegamarket.ru/catalog/aksessuary-dlya-telefonov/page-" )))
{	
	echo ' <br/>';
echo ' !!!!ВЕРОЯТНО ОШИБКА!!!!:';
$mailform =$mailform.'<a href="'.'https://www.sbermegamarket.ru'.$all[$num]->{'url'}.'">'.$all[$num]->{'item'}->{'name'}.' за '.$all[$num]->{'item'}->{'price'}.' стоил ранее '.$row['productPriceLocal'].'</a>\n'; 
$TMP2=$row['SENT']+1; 
$mysqli->query("UPDATE `{$tablename}` SET `SENT` = '{$TMP2}' WHERE `URL` LIKE '{$all[$num]->{'url'}}'");
}
$mysqli->query("UPDATE `{$tablename}` SET `productPriceLocal` = '{$all[$num]->{'item'}->{'price'}}' WHERE `URL` LIKE '{$all[$num]->{'url'}}'");
echo ' !!!!ОБНОВИЛИ!!!!';
$all[$num]->{'skidka'}=($row['productPriceLocal']-$all[$num]->{'item'}->{'price'})*100.0/$row['productPriceLocal'];


}
echo ' <br/>';
}
else
{   echo 'не нашли!!!';
$all[$num]->{'skidka'}=0;
	if($all[$num]->{'item'}->{'price'}!=0)
		$mysqli->query("INSERT INTO `{$tablename}` (`URL`, `productPriceLocal`,`bonus`,`productName`,`productCategoryName`) VALUES ('{$all[$num]->{'url'}}', '{$all[$num]->{'item'}->{'price'}}', '{$all[$num]->{'item'}->{'bonus_rub'}}', '{$all[$num]->{'name'}}', '{$all[$num]->{'item'}->{'category'}}')");
	else{
		echo '<br/><br/><br/><br/><br/><br/><br/><br/><br/> ОШИБКА СЧИТЫВАНИЯ <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>';
		$noprice++;
	}
}
$num++;
echo ' <br/>';echo ' <br/>';
}

if(strlen($mailform)>strlen("Скидка>70%(или > 50% при цене выше 10к)\n")+4)
{ echo "ОШИБКА ПИШУ НА ЕМАЙЛ";
	mail ( 'paulafanasiev@gmail.com', 'ОШИБКА! '.date("F j, Y, g:i a").' sbermegamarket ОШИБКА!', $mailform);
	message_to_telegram("sbermegamarket ".$mailform);
}
sleep (5);
}
usort($all, "cmp");

$testskidki=false;

$mailtmptotest="\nВсе скидки sbermegamarket в категории".$URLstartotest."\n";
foreach ($all as $value) {
	//echo '<a href="'.'https://www.perekrestok.ru'.$value->{'URL'}.'">'.$value->{'productName'}.' за '.$value->{'productPriceLocal'}.' скидка '.$value->{'skidka'}.'%</a>\n<br/>'; 
	if ($value->{'skidka'}>30){
		$testskidki=true;
		$mailtmptotest.='<a href="'.'https://www.sbermegamarket.ru'.$value->{'url'}.'">'.$value->{'item'}->{'name'}.' за '.$value->{'item'}->{'price'}.' скидка '.$value->{'skidka'}.'%</a>'."\n"; 
		//echo $mailall.'<br/>';
	}
}
if($testskidki)
	$mailall.=$mailtmptotest;
unset($all);
}

mysql_close();


$tmpmail='';
if($estskidki){
	$tmpmail="СКИДКИ ";
	}
	mail ( 'paulafanasiev@gmail.com', $tmpmail.date("F j, Y, g:i a").'sbermegamarket окончена проверка!', "sbermegamarket окончена проверка!\n".date("F j, Y, g:i a").$mailall);


















?>