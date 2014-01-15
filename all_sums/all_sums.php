<?php
class SuperArray{

	private $arr = array();
	private $pozitive_array = array();
	private $negative_array = array();
	
	function __construct($arr){
		$this->arr = $arr;
		$this->split(); // creates pozitive & negative arrays for sum() and pair() to use them later
	}

	function print_array(){
		$this->show($this->arr);
	}

	private function split(){
		foreach ($this->arr as $key => $value) {
			if($value>=0)// 0s will be in pozitive_array
			array_push($this->pozitive_array, $value);
			else
				array_push($this->negative_array, $value);
		}
	}

	function add($val){
		array_push($this->arr, $val);
	}



	function delete($val){
		foreach ($this->arr as $key => $value) {
			if ($value == $val)
				unset($this->arr[$key]);
		}
		$this->arr = array_values($this->arr);
	}

	function pairs(){
		$used = array();
		$num_of_negative = count($this->negative_array);
		if($num_of_negative>0)
		{
		$used = array_fill(0, $num_of_negative, 0); // fill with 0s. at the beginning, none of the elements are used
		foreach ($this->pozitive_array as $pkey => $pvalue) { // pkey, pvalue = pozitive_array key, value
			foreach ($this->negative_array as $nkey => $nvalue) { // nkey, nvalue = negative_array key, value
				if($pvalue == -$nvalue && !$used[$nkey])
				{
					echo "[$pvalue, $nvalue]\n";
					$used[$nkey] = 1; // if it was used, don't use it again
				}
			}
		}
	}
	$num_of_zeros = 0;
	foreach ($this->pozitive_array as $key => $value) {
		if ($value == 0) $num_of_zeros++;

	}

	for($i = 1;$i <= $num_of_zeros/2;$i++) //show [0, 0] for elements in the pozitive array which are equal to 0
	echo "[0, 0]\n";
}


function show($arr){ 
	$string = "[";
	foreach ($arr as $key => $value) {
		$string .= "$value,";
	}

	$string = substr_replace($string ,"",-1);
	$string .="]";

	echo $string; // simple display of [value1, value2,...]
}

function generate_sums($array){
	$sums_map = array();
	$num_of_elements = count($array);
	
	for ($i = 1; $i < pow(2, $num_of_elements); $i++) { // all numbers from 0 to 2^n(2^n being the number of subsets). Start from 1(0 in base 2)
		$aux = $i;
		$pos = 0;
		$sum = 0;
		$keys = array();
		while($aux){
			if($aux&1) // if bit $pos is 1, then add it to the subset
			{
				array_push($keys, $pos);
				$sum += $array[$pos];
			}
			$pos++;
			$aux = $aux>>1;
		}
		$pair = array();
		$pair['sum'] = $sum;
		$pair['keys'] = $keys;
		array_push($sums_map, $pair);
	}
	return $sums_map;  // ['sum'=>$sum, 'keys'=>[key1, key2,...]] structure
}

function zerosum(){
	$negative_sums = $this->generate_sums($this->negative_array);
	$pozitive_sums = $this->generate_sums($this->pozitive_array);
	
	foreach ($pozitive_sums as $pkey => $pvalue) { // pkey, pvalue = pozitive_array key, value
		foreach ($negative_sums as $nkey => $nvalue) { // nkey, nvalue = negative_array key, value
			if($pvalue['sum']+$nvalue['sum'] == 0)
			{
				$final_values = array();
				foreach ($pvalue['keys'] as $key => $value) {
					array_push($final_values, $this->pozitive_array[$value]);
				}

				foreach ($nvalue['keys'] as $key => $value) {
					array_push($final_values, $this->negative_array[$value]);
				}

				$this->show($final_values);
				echo "\n";
				unset($negative_sums[$nkey]); // don't take values twice
			}

		}
	}

	$num_of_zeros = 0;
	foreach ($this->pozitive_array as $key => $value) {
		if ($value == 0) $num_of_zeros++;

	}

	for($i = 1; $i <= $num_of_zeros/2; $i++) //show [0, 0] for elements in the pozitive array which are equal to 0
	echo "[0, 0]\n";
}

}

$array = new SuperArray([-3, 6, 5, 3, 10, 6, 2, 3, 9, -3, -2, -5]);
// $array->zerosum();
// $array->delete(-3);
// $array->add(-3);
// $array->add(-3);
// $array->delete(-3);
// $array->delete(3);
$array->print_array();

?>