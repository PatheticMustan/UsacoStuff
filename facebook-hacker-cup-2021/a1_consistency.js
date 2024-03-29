const input = `45
EMLEKLIXUPNUEAUEAXUCKHPUEJBUIAKJTKCYIGITCIAUPIQAZUO
UUKWEQAESOAANZPGYMYEDHQEQZWUPZRZIHIIYEUEICKALGANOHKMIEXMXCUAXXYLODOZKEOUGDFKCNI
OWAMBXIRMUNOIXEUJILQLAPGLHQSFXUNAJLIERKUQEGCIYNHHEEYFHOFIAMH
ABC
RGQQRTUSHOIUEJBEYZSHIIRDASATUUPUBKTHHUZNTPNLOILOOQYU
FBHC
IOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOI
OEOUAEOUAUAEIEIIIAIOOUAUIAEEUUIAIAIOUIIAUUIIUAUUEAOAOAEEUEUOUAOAIOUUEEIEAUOAIOEEOUIOAUOEOIAEO
IOAOIAAOAEOIEIEAIIEAOUEIEIOOIEIEOIEIOEOUUOEUEOAOEIOOUUUIIOAEIAIEIOIEUOIUUEIEAEIAAIEOE
PTCJRYMLRWZVMZZPBKPNSDMFTCFKLCZXLPQLNQCLDXQVQZMYHBXPLQMXMHJQFKLHNXTKCRZMRKBWDTBBPYFTMLBQZMVVRBTXBCM
AIIOEAAAUEUUOEOOUAIIIIOEEIEAAAAUAIAEUUOUEUOAUAOIUAOUAAIUIIIE
UFOVKZEOUTPUJSWEITEUAIYDRIBGUIUIOEII
KDIYULAIEGHARWVOIKBAUTEINPMEBAPRETFOUL
HLVTMEAUMYEDMFIMUMEEBEUKEAITNWOIIOSGTIAUPBUINUQGYOAAAETCJGOEMWQEAOPUTTDAAQEESKISO
ZVOIAGIMOLAHOAIAJEIUBHLNDDFIHGZHCIUWRMGIHIUOPICDOURTUVAOO
AHKELEGPWUNIMUEIUAFOEMAJVFNAEGDOIPASOCLZGPBEAZECGJUUOKHFZSIICWUGRGEAAIZANQIEFVNANAITXIOVDVAEOE
QPQWJXRJJXBTKKGBKVXNSCQBHZTSFZRYCDZFYQJQWHWHYJVDRXSGWRLJNTHBXYBRBTVXBBPPCXRBFVXVNDQQTHHBKXZDPQZGSHWF
AOEEUOAOOUEUUUUEEOAOIOOAAEIEAIEUOIAOOAIOUAAUIUEUIOIUUEEOOAEOIEUIUOOOIEIUEIAEEIIEIEEEEAUIOEIIUE
OEOQUIAFDWEXDKOSAFVUMBBYVEUUWDETZUGNHWJEIWAIHITNAMFLYPIGJOLAOCPFOTOEHVEARVPXCSTITMHA
OOOYSRHWNQELBPPMEPOMAZUEZWZAUBAOHNEEYXACMAKUUHUEAULHHBILUHWIONXKNFEAIAZOEUXIZOKJBUONPQAXPEOIRCX
AAAAAEEEEEIIIIIOOOOOOUUUUUXYZ
GJNZWNDWKKNPLRRBSSDNHXFZ
FBBNOBTGQYATFOVKWIHAHOXQRNOAAIEUUUIKGFQMGEWYYINOIIEQNQHOQKOOLIXIAKOFEURNOZUKAGAVQAYNQ
OOEUEUIUUOOAUEIOIEEUIAIUAUOOAUUIIEUUOAAIOAEAUEIAOAOOAOOAAIEOAEOEIOIAAEAAIOEEOIIIEEIOIUEIEEEAAEEEEOAA
ALECOEAGWFOIEERMFTABOYKUCIXJRZMV
AAAAAAAAAAEEEEEEEEEEIIIIIIIIIIOOOOOOOOOOUUUUUUUUUUBBBBBBBBBBBCCCCDDDDFFFFGGGGHHHHJJJJKKKKLLLLMMMMNNN
EJZITADGAAAKTEIQVEWLLIIZXWLKSEAIUUUIERFKEUOXONORJRXGKGLIUIUBNXINNJHHAEAACBEQWXZ
OBHMEAIJAJEROOFEHOHEYEVGHHOOUTIPAETOEAQOJVICAUNLWNUL
CONSISTENCY
OKMEOEQIUSFATUOTONBRYEEUUUDGEITUGRARKUIUGOJIAOEGUKJOPIAYZBGKOEFOFHOXIJTCEOOEMSSOFCEXIUYOF
OIOUAUOAIEUOEUIUIIUAAAAUOEIEUAIEEOIAOEUEAOOEAIIEEAEIUIOAUIIOEEUEAOEOOAAIAUAO
OXEOURJOEUEJUUTUEIEQORXSBGLUIIARAVUBPUICEIJAIILEQDBIIQONE
LNJYCVQZUUIKAFAIJSVMZPT
KTNIUDNSSOOFAMLGAXJGKXOEBHGEOGQQELSAAEZAGKEFEYYRLETFAEBOAHASLIZUUEAGCP
SYMPHXFDDRQRPMZTJBVFYWMPLGBRBPRYMTTBDBNTMTJFYJ
HAAACKEEERCUUUP
F
EDHHDGFGCFHBHCAFGHHCBDHHECAEGGAGAGDGEGGFDGBCDFDCBHFGBDBCGHEACCGFAGEFBFGECFGFCGGBEDGDBFCEHEDHEHHFGCEB
MYNTULUYAUBJWTUHTUUOWEOUUIQPGPKFPEAUUAOOARIVSDIQEIMCUIQUQDAUAIIENPILCBGIOCVNUR
IEOFAAANDPZTKXEOBULZIEL
EASAYUEOXQXEAKAFIUOEAALAUIIUUGPA
AYOOZMUIADIDNXXHTMDEFFDDJIMPJANSTOAUHSAIGAFXJHTAABWUZBURBOVJEDZICDOBEAXIJADNLMSKHAOAFEJPHWIAHC
BANANA
FOXEN
UVZVEOMIJOOAWGLCIEIAUBSQPRM`.split("\n");
// haha first line doesn't matter
input.shift();

// look, I'm not very good at naming things, alright?
// vowelIndex is an array of the vowels
const alphabetString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const vowelIndex = [0, 4, 8, 14, 20];

const isVowel = letter => "AEIOU".includes(letter)

const output = input.map(testcase => {
    // keep track of the occ of letters
    let letterCount = new Array(26).fill(0);
    testcase.split("").map(v => letterCount[alphabetString.indexOf(v)]++);

    // count vowels and consonants
    let consonantCount = 0;
    let vowelCount = 0;
    testcase.split("").map(v => (isVowel(v)? vowelCount++ : consonantCount++));

    // oh yeah yeah, infinity
    let min = Infinity;

    letterCount.map((v, i) => {
        if (v === 0) return;
        let poop = isVowel(alphabetString[i]);
        let res = Infinity;

        if (poop) {
            res = consonantCount + ((vowelCount-v)*2);
        } else {
            res = vowelCount + ((consonantCount-v)*2);
        }

        min = Math.min(min, res);
    });

    // edge cases where the letters switch to no common letter
    if (consonantCount == 0) min = Math.min(min, vowelCount);
    if (vowelCount == 0) min = Math.min(min, consonantCount);
    
    return min;
})





console.log(output.map((v, i) => `Case #${i+1}: ${v}`).join("\n"));