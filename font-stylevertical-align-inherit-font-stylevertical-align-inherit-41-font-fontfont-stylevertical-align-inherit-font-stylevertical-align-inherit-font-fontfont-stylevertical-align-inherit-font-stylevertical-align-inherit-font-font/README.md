<h2><a href="https://leetcode.com/problems/first-missing-positive/"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">41 </font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">. </font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">첫 번째 누락 양성</font></font></a></h2><h3>Hard</h3><hr><div><p><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">정렬되지 않은 정수 배열이 주어지면 </font></font><code>nums</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">누락된 가장 작은 양의 정수를 반환합니다.</font></font></p>

<p><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">시간 내에 실행되고 일정한 추가 공간을 사용하는 알고리즘을 구현해야 합니다 </font></font><code>O(n)</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">.</font></font></p>

<p>&nbsp;</p>
<p><strong class="example"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">예 1:</font></font></strong></p>

<pre><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">입력:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> nums = [1,2,0]
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">출력:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 3
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">설명:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> [1,2] 범위의 숫자가 모두 배열에 있습니다.
</font></font></pre>

<p><strong class="example"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">예 2:</font></font></strong></p>

<pre><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">입력:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> nums = [3,4,-1,1]
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">출력:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 2
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">설명:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 1은 배열에 있지만 2는 없습니다.
</font></font></pre>

<p><strong class="example"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">예 3:</font></font></strong></p>

<pre><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">입력:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> nums = [7,8,9,11,12]
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">출력:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 1
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">설명:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 가장 작은 양의 정수 1이 없습니다.
</font></font></pre>

<p>&nbsp;</p>
<p><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">제약:</font></font></strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>
</div>