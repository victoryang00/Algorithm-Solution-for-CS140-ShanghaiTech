        while (temp->next != nullptr) {
            if (current_height < maximum) {
                temp = temp->next;
                break;
            } else if (temp->next->m_height < maximum) {
                temp = temp->next;
            } else {
                maximum = maximum >= temp->next->m_height ? maximum : temp->next->m_height;
                count++;
                // cout<<"pair"<<" ( "<<current_height<<","<<temp->next->m_height<<" )"<<endl;
                temp = temp->next;
            }
        }