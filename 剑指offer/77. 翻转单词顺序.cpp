 /*
 输入一个英文句子，单词之间用一个空格隔开，且句首和句尾没有多余空格。

翻转句子中单词的顺序，但单词内字符的顺序不变。

为简单起见，标点符号和普通字母一样处理。

例如输入字符串"I am a student."，则输出"student. a am I"。
 */

//字符串以字母为级别的翻转
for(int i=0,j=s.size();i<j;i++,j--)swap(s[i],s[j]);

//字符串以单词为级别的翻转
//通过操作分解的角度进行思考
//第一步，直接翻转每个句子
//第二步，翻转每个单词
//矩阵两次旋转操作，并且只使用O(1)的空间
class Solution {
public:
    string reverseWords(string s) {
        //第一步，直接翻转整个字符串
        reverse(s.begin(),s.end());
        //第二步，翻转每个单词
        //找连续的字符
        for(int i=0;i<s.size();i++)
        {
            int j=i;
            while(j<s.size()&&s[j]!=' ')j++;
            reverseWords(s.begin()+i,s.begin()+j);
            i=j;
        }      
    }
};