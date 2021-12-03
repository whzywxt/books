import re
from xpinyin import Pinyin


def alter(file, old_str='', new_str=''):
    """
    替换文件中的字符串
    :param file:文件名
    :param old_str:就字符串
    :param new_str:新字符串
    :return:
    """
    p = Pinyin()
    file_data = ""
    title_pattern = 'title: ?"(.*)?"'
    slug_pattern = 'slug:(.*)?'
    with open(file, "r", encoding="utf-8") as f:
        for line in f:
            match_slug = re.match(slug_pattern, line, re.M | re.I)
            print(match_slug)
            if match_slug:
                slug = match_slug.group(1)
                if slug:
                    line = ''

            match_title = re.match(title_pattern, line, re.M | re.I)
            if match_title:
                title = match_title.group(1)
                if title:
                    title_pinyin = p.get_pinyin(title, ' ')
                    print(title_pinyin)
                    title_pinyin = re.sub("[^a-zA-Z-0-9.]+", " ", title_pinyin)
                    title_pinyin = re.sub(" +", " ", title_pinyin)
                    print(title_pinyin)
                    new_str = 'slug: "' + title_pinyin + '"\n'
                    line = new_str + line

            file_data += line
    with open(file, "w", encoding="utf-8") as f:
        f.write(file_data)

# alter("C:\www\code\whzywxt.github.io\content\post\PHP常用算法.md", "PHP常用算法", "python")
