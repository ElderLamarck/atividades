email = input()
final_email = 'certo'

while email != 'sair':
    email_split_dot = email.split('.')
    email_split_at = ' '.join(email_split_dot)
    email_split_at = email_split_at.split('@')
    email_split_space = ' '.join(email_split_at)
    email_for_analyze = email_split_space.split(' ')

    for letters in email_for_analyze:

        if letters == '':
            final_email = 'errado'
            break
        elif len(email_for_analyze) != 4:
            final_email = 'errado'
            break

        else: final_email = 'certo'

    print(final_email)
    email = input()